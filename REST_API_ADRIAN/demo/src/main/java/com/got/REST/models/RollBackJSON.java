package com.got.REST.models;
import java.io.Serializable;


public class RollBackJSON implements Serializable{

	private String file;
	private String idCommit;
	private String repositoryName;
	
	
	public RollBackJSON() {
	}
	

	public RollBackJSON(String file, String idCommit, String repositoryName) {
		super();
		this.file = file;
		this.idCommit = idCommit;
		this.repositoryName = repositoryName;
	}
	
	public String getIdCommit() {
		return idCommit;
	}

	public void setIdCommit(String idCommit) {
		this.idCommit = idCommit;
	}

	public String getFile() {
		return file;
	}
	public void setFile(String file) {
		this.file = file;
	}

	
	
	public String getRepositoryName() {
		return repositoryName;
	}
	public void setRepositoryName(String repositoryName) {
		this.repositoryName = repositoryName;
	}
	
	
}	
