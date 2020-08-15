package com.got.REST.models;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "commits")  //Nombre de la tabla
public class Commit implements Serializable{

	private static final long serialVersionUID = 1L;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private long idCommit;
	
	private String message;
	
	private String date;
	
	private int idRepository;
	
	
	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}



	public long getIdCommit() {
		return idCommit;
	}

	public void setIdCommit(long id) {
		this.idCommit = id;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public int getIdRepository() {
		return idRepository;
	}

	public void setIdRepository(int idRepository) {
		this.idRepository = idRepository;
	}

	public Commit(String date, String message, int idRepository) {
		super();
		this.date = date;
		this.idRepository = idRepository;
		this.message = message;
	}

	public Commit() {
	}
	
	
	
}
