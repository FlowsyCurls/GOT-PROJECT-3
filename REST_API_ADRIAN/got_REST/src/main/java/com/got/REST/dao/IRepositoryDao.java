package com.got.REST.dao;
import org.springframework.data.repository.CrudRepository;

import com.got.REST.models.Repository;

public interface IRepositoryDao extends CrudRepository<Repository, Long> {

}
