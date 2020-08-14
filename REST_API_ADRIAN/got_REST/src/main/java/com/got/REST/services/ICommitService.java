package com.got.REST.services;

import java.util.List;

import com.got.REST.models.Commit;

public interface ICommitService {

	public Commit get(long id);
	public List<Commit> getAll();
	public void post(Commit commit);
	public void put(Commit commit, long id, String date, int idRepository);
	public void delete(long id);
	
}
