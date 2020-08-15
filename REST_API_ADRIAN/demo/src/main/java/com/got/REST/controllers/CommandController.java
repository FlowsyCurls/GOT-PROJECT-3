package com.got.REST.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

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
}
