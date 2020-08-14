package com.got.REST.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RestController;

import com.got.REST.models.Commit;
import com.got.REST.services.ICommitService;

@RestController
public class CommitController {

	@Autowired
	ICommitService commitService;
	
	@GetMapping("/Commits")
	public List<Commit> getAllCommits(){
		
		return commitService.getAll();
	}
	
	@GetMapping("/Commit/{id}")
	public Commit getOneCommit(@PathVariable(value = "id") long id) {
		return commitService.get(id);
	}
	
	@PostMapping("/Commit")
	public void addCommit(Commit commit) {
		commitService.post(commit);
	}
	
	@PutMapping("/Commit")
	public void updateCommit(Commit commit, long id, int idRepository, String date) {
		commitService.put(commit, id, date, idRepository);
	}
	
}
