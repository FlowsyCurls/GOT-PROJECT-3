package com.got.REST.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.got.REST.dao.IRepositoryDao;
import com.got.REST.models.Repository;

@Service
public class RepositoryServiceImpl implements IRepositoryService{

	@Autowired
	private IRepositoryDao repositoryDao;
	
	@Override
	public Repository get(long id) {
		return repositoryDao.findById(id).get();
	}

	@Override
	public List<Repository> getAll() {
		return (List<Repository>) repositoryDao.findAll();
	}

	@Override
	public void post(Repository repository) {
		repositoryDao.save(repository);
	}

	@Override
	public void put(Repository repository, long id) {
		repositoryDao.findById(id).ifPresent((x)->{
			
			repository.setId(id);
			repositoryDao.save(repository);
			
		});
		
	}

	@Override
	public void delete(long id) {
		repositoryDao.deleteById(id);
	}

	
}
