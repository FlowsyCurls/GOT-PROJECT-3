package com.got.REST.services;

import java.util.List;

import com.got.REST.models.File;

public interface IFileService {
	public File get(long id);
	public List<File> getAll();
	public void post(File file);
	public void put(File file, long id, String content, int idCommit);
	public void delete(long id);
}
