package com.got.REST.models;

import java.io.Serializable;

public class CommitEntityJSON implements Serializable{
	
	private String huffmanCode;
	private String name;
	boolean toCommit;
	public String getHuffmanCode() {
		return huffmanCode;
	}
	public void setHuffmanCode(String huffmanCode) {
		this.huffmanCode = huffmanCode;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public boolean isToCommit() {
		return toCommit;
	}
	public void setToCommit(boolean toCommit) {
		this.toCommit = toCommit;
	}
	public CommitEntityJSON(String huffmanCode, String name, boolean toCommit) {
		super();
		this.huffmanCode = huffmanCode;
		this.name = name;
		this.toCommit = toCommit;
	}
	public CommitEntityJSON() {
	}
	
	

}
