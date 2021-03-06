package com.got.REST.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RestController;

import com.got.REST.models.Repository;
import com.got.REST.services.IRepositoryService;

@RestController
public class RepositoryController{

	@Autowired
	IRepositoryService repositoryService;
	
	@GetMapping("/Repositories")
	public List<Repository> getAllRepositories(){
		return repositoryService.getAll();
	}
	
	@GetMapping("/Repository/{id}")
	public Repository getOne(@PathVariable(value = "id") long id) {
		return repositoryService.get(id);
	}
	
	@PostMapping("/Repository")
	public void add(Repository repository) {
		repositoryService.post(repository);
	}
	
	@PutMapping("/Repository")
	public void update(Repository repository, long id) {
		repositoryService.put(repository, id);
	}
	
	
	
	
}

