package com.got.REST.controllers;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.List;

import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import com.got.REST.models.Commit;
import com.got.REST.models.CommitEntityJSON;
import com.got.REST.models.CommitJSON;
import com.got.REST.models.File;
import com.got.REST.models.MD5;
import com.got.REST.models.Repository;
import com.got.REST.models.RollBackJSON;
import com.got.REST.services.IFileService;
import com.got.REST.services.ICommitService;
import com.got.REST.services.IRepositoryService;

@RestController
public class CommandController {
	
	@Autowired
	IRepositoryService repositoryService;
	
	@Autowired
	ICommitService commitService;
	
	@Autowired
	IFileService fileService;
	
	private MD5 md5 = new MD5();
	

	
	
	// MD5
	private String encode(String id) {
		return md5.encrypt(id);
	}
	private boolean decode(String orig, String compare) {		
		return md5.matching(orig, compare);
	}
	
	
	
	// REPOSITORIES //
	
	// By ID
	private Repository getRepository(long id) {
		return repositoryService.get(id);
	}
	
	// By Name
	private Repository getRepository(String name) { 
		List<Repository> lista = repositoryService.getAll();	
		for(int i = 0; i < lista.size(); i++) { 
			if(lista.get(i).getName().contains(name)) { 
				return lista.get(i);
			}
		}
		return null;
	}
	
	
	
	// COMMITS //
	
	// Get ALL Commits in repo.
	private List<Commit> getCommits(long id) {
		List<Commit> tmp = commitService.getAll();
		
		// PD: No supe como inicializar un List <Commit>  nuevo xd;
		List<Commit> commits = commitService.getAll();
		commits.clear();
		
		for(int i = 0; i < tmp.size(); i++) {
			if(tmp.get(i).getIdRepository() == id) {
				commits.add(tmp.get(i));
			}
		}
		return commits;
	}
	
	// By ID
	private Commit getCommit(long id) {
		return commitService.get(id);
	}
	
	// By Message
	private Commit getCommit(String message) {
		List<Commit> lista = commitService.getAll();
		for(int i = 0; i < lista.size(); i++) {
			Commit tmp = lista.get(i);
			if(tmp.getMessage().contains(message)){ 
				return tmp;
			}
		}
		return null;
	}
	
	private Commit getCommit(long repositoryID, String encoded) {
		List<Commit> tmp = getCommits(repositoryID);
		for(int i = 0; i < tmp.size(); i++) {
			if (decode(encoded, String.valueOf(tmp.get(i).getIdCommit()))) {
				return tmp.get(i);
			}
		}
		return null;
	}
	
	
	
	
	// FILE //
	
	// By ID
	private File getFile(long id) {
		return fileService.get(id);
	}
	
	// By Name
	private File getFile(String name) {
		List<File> lista = fileService.getAll();
		for(int i = 0; i < lista.size(); i++) { 
			if(lista.get(i).getName().contains(name)) { 
				return lista.get(i);
			}
		}
		return null;
	}

	// By Rollback
	private File getFile(String name, String IdCommit) {
		List<File> lista = fileService.getAll();
		for(int i = 0; i < lista.size(); i++) { 
			File file = lista.get(i);
			if(file.getName().equals(name) && file.getIdCommit() == Integer.valueOf(IdCommit)) { 
				return lista.get(i);
			}
		}
		return null;
	}
	
	// By Name
	private File getLastCommitFile(String name) {
		List<File> lista = fileService.getAll();
		long tmp = 0;
		for(int i = 0; i < lista.size(); i++) { 
			if(lista.get(i).getName().equals(name)) { 
				tmp = lista.get(i).getIdFile();
			}
		}
		return getFile(tmp);
	}
	
	
	
	
	@GetMapping("/Commits/{name}")
	public String getCommitsString(@PathVariable(value = "name") String name){
		Repository repository = getRepository(name);
		List<Commit> commits = getCommits(repository.getId());
		String s = "";
		for (int i = 0; i < commits.size(); i++) {
			Commit commit = commits.get(i);
			s += encode(String.valueOf(commit.getIdCommit())) + "\t" + commit.getMessage() + "\t" + commit.getDate() +"\n";
		}
		return s;
	}
	

	@GetMapping("/getFile/{id}")
	public String getFileInfo(@PathVariable(value = "id") long id){	
		Repository repository = getRepository(id);
		String s = "id: " + repository.getId() + "Repository name: " + repository.getName();
		return s;
	}
	
	@PostMapping("/newCommit")
	public @ResponseBody String commit(@RequestBody CommitJSON commitJson) {
		Repository repository = getRepository(commitJson.getRepositoryName());
		// Create Commit.
		String date = new SimpleDateFormat("yyyyMMdd_HHmmss").format(Calendar.getInstance().getTime());
		Commit commit = new Commit(date, commitJson.getMessage(), (int)repository.getId());
		commitService.post(commit);
		commit = getCommit(commit.getMessage());
		// Create Files.
		for(int i = 0; i < commitJson.getFileList().size(); i++) {
			File file = new File(date, commitJson.getFileList().get(i).getName(), (int)commit.getIdCommit(), commitJson.getFileList().get(i).getContent());
			fileService.post(file);
		}
		return encode(String.valueOf(commit.getIdCommit()));
	}
	
	
	/**
	 * Permite regresar un archivo en el tiempo a un commit específico. Para esto, se comunica al server y
	 * recupera el archivo hasta dicha version.
	 * @param rollback
	 * @return
	 */
	@PostMapping("/rollback")
	public @ResponseBody String rollback(@RequestBody RollBackJSON rollback) {
	
		// Get Repository.
		Repository repository = getRepository(rollback.getRepositoryName());
		if (repository==null) return "Error: No existe repositorio";
		
		// Get Commit.
		Commit commit = getCommit(repository.getId(), rollback.getIdCommit());
		if (commit==null) return "Error: No existe commit";
		
		// Get File.
		File file = getFile(rollback.getFile(), String.valueOf(commit.getIdCommit()));
		
		// Prints
		System.out.println("File " + file.getName() + " restored to commit " + commit.getIdCommit() + " : " + commit.getMessage());
		System.out.println("File Content" + file.getContent());
		System.out.println("File Date" + file.getDate());
		
		return file.getContent();
	}
	
	/**
	 * Deshace cambios locales para un archivo y lo regresa al último commit.
	 * @param name
	 * @return
	 */
	@PostMapping("/reset")
	public String reset(String name) {
		System.out.println(name);
		return getLastCommitFile(name).getContent();
	}
	
	/*
	@PutMapping("/Repository")
	public void update(Repository repository, long id) {
		repositoryService.put(repository, id);
	}
	*/


	
	
}
