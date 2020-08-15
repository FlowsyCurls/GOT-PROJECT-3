package com.got.REST.dao;

import org.springframework.data.repository.CrudRepository;

import com.got.REST.models.File;

public interface IFileDao extends CrudRepository<File, Long>{
	
}
