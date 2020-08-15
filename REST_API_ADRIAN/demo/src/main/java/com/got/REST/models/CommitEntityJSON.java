package com.got.REST.models;

import java.io.Serializable;

public class CommitEntityJSON implements Serializable{
	

	private String content;
	private String huffmanCode;
	private String name;	
	boolean toCommit;
	
	
	public CommitEntityJSON(String content, String huffmanCode, String name, boolean toCommit) {
		super();
		this.content = content;
		this.name = name;
		this.toCommit = toCommit;
	}
	public CommitEntityJSON() {
	}
	
	
	
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
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

	

}
