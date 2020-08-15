package com.got.REST.dao;
import org.springframework.data.repository.CrudRepository;
import com.got.REST.models.Commit;

public interface ICommitDao extends CrudRepository<Commit, Long>{

}
