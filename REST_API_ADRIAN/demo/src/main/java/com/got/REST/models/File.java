package com.got.REST.models;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "files")  //Nombre de la tabla
public class File implements Serializable {

	private static final long serialVersionUID = 1L;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private long idFile;
	
	private String date;
	
	private int idCommit;
	
	private String content;
	

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	public long getIdFile() {
		return idFile;
	}

	public void setIdFile(long id) {
		this.idFile = id;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public int getIdCommit() {
		return idCommit;
	}

	public void setIdCommit(int idCommit) {
		this.idCommit = idCommit;
	}

	public File(String date, int idCommit, String content) {
		super();
		this.date = date;
		this.idCommit = idCommit;
		this.content = content;
	}

	public File() {
	}
	
	
}
