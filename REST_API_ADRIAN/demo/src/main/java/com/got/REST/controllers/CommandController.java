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
	
	
	private File getFile(long id) {
		List<File> lista = fileService.getAll();
		for(int i = 0; i < lista.size(); i++) { 
			if(lista.get(i).getIdFile() == id) { 
				return lista.get(i);
			}
		}
		return null;
	}
	
	private Repository getRepository(long id) { 
		List<Repository> lista = repositoryService.getAll();
		for(int i = 0; i < lista.size(); i++) { 
			if(lista.get(i).getId() == id) {
				return lista.get(i);
			}
		}
		return null;
	}
	
	private Repository getRepositoryByName(String name) { 
		List<Repository> lista = repositoryService.getAll();
		for(int i = 0; i < lista.size(); i++) { 
			if(lista.get(i).getName().contains(name)) { 
				return lista.get(i);
			}
		}
		return null;
	}
	
	
	private Commit getCommit(Commit commit) {
		List<Commit> lista = commitService.getAll();
		for(int i = 0; i < lista.size(); i++) {
			Commit tmp = lista.get(i);
			if(tmp.getMessage().contains(commit.getMessage())){ 
				return tmp;
			}
		}
		return null;
	}
	
	
	@GetMapping("/getFile/{id}")
	public String getFileInfo(@PathVariable(value = "id") long id){	
		File file = getFile(id);
		Repository repository = getRepository(id);
		String s = "id: " + repository.getId() + "Repository name: " + repository.getName();
		return s;
	}
	
	@PostMapping("/newCommit")
	public @ResponseBody String add(@RequestBody CommitJSON commitJson) {
		Repository repository = getRepositoryByName(commitJson.getRepositoryName());
		// Create Commit.
		String date = "21-10-00";
		System.out.println("LLega");
		Commit commit = new Commit(date, commitJson.getMessage(), (int)repository.getId());
		System.out.println("Pasa new");
		commitService.post(commit);
		System.out.println("Se agrega commit");

		commit = getCommit(commit);
		// Create Files.
		for(int i = 0; i < commitJson.getFileList().size(); i++) {
			
			File file = new File(date, (int)commit.getIdCommit(), commitJson.getFileList().get(i).getHuffmanCode());
			fileService.post(file);
		}
		return String.valueOf(commit.getIdCommit());
	}
	
	/*
	@PutMapping("/Repository")
	public void update(Repository repository, long id) {
		repositoryService.put(repository, id);
	}
	*/


	
	
}
