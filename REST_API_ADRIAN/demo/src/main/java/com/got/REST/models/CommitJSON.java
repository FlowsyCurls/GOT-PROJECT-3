package com.got.REST.models;

import java.io.Serializable;
import java.util.List;

public class CommitJSON implements Serializable{
	
	private String repositoryName;
	private String message;
	private List<CommitEntityJSON> fileList;
	
	
	public CommitJSON(String repositoryName, List<CommitEntityJSON> fileList) {
		super();
		this.repositoryName = repositoryName;
		this.fileList = fileList;
	}
	public CommitJSON() {
	}
	
	
	public String getRepositoryName() {
		return repositoryName;
	}
	
	
	public void setRepositoryName(String repositoryName) {
		this.repositoryName = repositoryName;
	}
	
	public List<CommitEntityJSON> getFileList() {
		return fileList;
	}
	
	public void setFileList(List<CommitEntityJSON> fileList) {
		this.fileList = fileList;
	}

	public String getMessage() {
		return message;
	}
	public void setMessage(String message) {
		this.message = message;
	}
	
	

}
