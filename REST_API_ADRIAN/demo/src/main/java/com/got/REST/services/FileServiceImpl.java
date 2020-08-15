package com.got.REST.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.got.REST.dao.IFileDao;
import com.got.REST.models.File;

@Service
public class FileServiceImpl implements IFileService{

	@Autowired
	private IFileDao fileDao;
	
	@Override
	public File get(long id) {
		return fileDao.findById(id).get();
	}

	@Override
	public List<File> getAll() {
		return (List<File>) fileDao.findAll();
	}

	@Override
	public void post(File file) {
		fileDao.save(file);
	}

	@Override
	public void put(File file, long id, String content, int idCommit) {
		fileDao.findById(id).ifPresent((x)->{
			
			file.setIdFile(id);
			fileDao.save(file);
			
		});
	}

	@Override
	public void delete(long id) {
		fileDao.deleteById(id);
	}

}
