package com.got.REST.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import com.got.REST.models.CommitEntityJSON;
import com.got.REST.models.CommitJSON;
import com.got.REST.models.File;
import com.got.REST.models.Repository;
import com.got.REST.services.IFileService;
import com.got.REST.services.IRepositoryService;

@RestController
public class CommandController {
	
	@Autowired
	IRepositoryService repositoryService;
	
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
	
	
	@GetMapping("/getFile/{id}")
	public String getFileInfo(@PathVariable(value = "id") long id){
		
		
		File file = getFile(id);
		Repository repository = getRepository(id);
		
		String s = "id: " + repository.getId() + "Repository name: " + repository.getName();
		
		
		return s;
		
		
	}
	
	@PostMapping("/newCommit")
	public @ResponseBody String add(@RequestBody CommitJSON commit) {
		
		System.out.println(commit.getRepositoryName());
		
		//Tiene que agregar un nuevo commit que debe tener date y idRepository
		//Tiene que agregar la lista de archivos que tiene commitJson y ponerles sus atributos
		
		
		
		
		/*
		List<Repository> listOfRepositories = commitService.getAll();
		
		for(int i = 0; i < listOfRepositories.size(); i++) { 
			
			if(listOfRepositories.get(i).getName().contains(commit.getName())) { 
				
				return "Ya existe un repositorio con este nombre"; //No se agrega a la tabla porque ya existe
				
			}
			
		}
		
		repositoryService.post(commit);
		*/
		return "Saved";
	}
	/*
	@PutMapping("/Repository")
	public void update(Repository repository, long id) {
		repositoryService.put(repository, id);
	}
	*/
	
	
}
