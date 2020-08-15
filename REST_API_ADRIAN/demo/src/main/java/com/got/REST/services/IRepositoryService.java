package com.got.REST.services;

import java.util.List;

import com.got.REST.models.Repository;

public interface IRepositoryService {

	public Repository get(long id);
	public List<Repository> getAll();
	public void post(Repository repository);
	public void put(Repository repository, long id);
	public void delete(long id);
	
}
