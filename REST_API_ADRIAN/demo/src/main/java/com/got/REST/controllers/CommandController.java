package com.got.REST.controllers;

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
	private File getFile(RollBackJSON rollback) {
		List<File> lista = fileService.getAll();
		for(int i = 0; i < lista.size(); i++) { 
			File file = lista.get(i);
			if(file.getIdCommit() == Integer.valueOf(rollback.getIdCommit()) && file.getName().contains(rollback.getFile())) { 
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
		String date = "21-10-00";
		Commit commit = new Commit(date, commitJson.getMessage(), (int)repository.getId());
		commitService.post(commit);
		commit = getCommit(commit.getMessage());
		// Create Files.
		for(int i = 0; i < commitJson.getFileList().size(); i++) {
			File file = new File(date, commitJson.getFileList().get(i).getName(), (int)commit.getIdCommit(), commitJson.getFileList().get(i).getHuffmanCode());
			fileService.post(file);
		}
		return String.valueOf(commit.getIdCommit());
	}
	
	
	/**
	 * Permite regresar un archivo en el tiempo a un commit específico. Para esto, se comunica al server y
	 * recupera el archivo hasta dicha version.
	 * @param rollback
	 * @return
	 */
	
	@PostMapping("/rollback")
	public @ResponseBody String rollback(@RequestBody RollBackJSON rollback) {
		System.out.println(rollback.getFile());
		System.out.println(rollback.getIdCommit());
		System.out.println(rollback.getRepositoryName());
		// Get Repository.
		Repository repository = getRepository(rollback.getRepositoryName());
		if (repository==null) return "Error: No existe repositorio";
		// Get Commit.
		Commit commit = getCommit(Integer.valueOf(rollback.getIdCommit()));
		if (commit==null) return "Error: No existe commit";
		// Get File.
		File file = getFile(rollback);
		System.out.println("Last Content" + file.getIdFile());
		System.out.println(file.getContent());
		String lastcontent = file.getContent();
		return lastcontent;
	}
	
	/**
	 * Deshace cambios locales para un archivo y lo regresa al último commit.
	 * @param name
	 * @return
	 */
	@PostMapping("/reset")
	public @ResponseBody String reset(String name) {
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
