package com.got.REST.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RestController;

import com.got.REST.models.Commit;
import com.got.REST.models.File;
import com.got.REST.services.IFileService;

@RestController
public class FileController {
	
	@Autowired
	IFileService fileService;
	
	@GetMapping("/Files")
	public List<File> getAllCommits(){
		
		return fileService.getAll();
	}
	
	@GetMapping("/File/{id}")
	public File getOneCommit(@PathVariable(value = "id") long id) {
		return fileService.get(id);
	}
	
	@PostMapping("/File")
	public void addCommit(File file) {
		fileService.post(file);
	}
	
	@PutMapping("/File")
	public void updateCommit(File file, long id, String content, int idCommit) {
		fileService.put(file, id, content, idCommit);
	}

}
