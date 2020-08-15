package com.got.REST.models;

import java.math.BigInteger;

public class MD5 {
	
	public MD5() {
	}
	
	public String encrypt(String md5) {
	   try {
	        java.security.MessageDigest md = java.security.MessageDigest.getInstance("MD5");
	        byte[] array = md.digest(md5.getBytes());
	        StringBuffer sb = new StringBuffer();
	        for (int i = 0; i < array.length; ++i) {
	          sb.append(Integer.toHexString((array[i] & 0xFF) | 0x100).substring(1,3));
	        }
	        return sb.toString();
	    } catch (java.security.NoSuchAlgorithmException e) {
	    }
	   return null;
	}


	public static boolean matching(String orig, String compare){
	    String md5 = null;
	    try{
	    	java.security.MessageDigest md = java.security.MessageDigest.getInstance("MD5");
	        md.update(compare.getBytes());
	        byte[] digest = md.digest();
	        md5 = new BigInteger(1, digest).toString(16);
	        return md5.equals(orig);
	    } catch (java.security.NoSuchAlgorithmException e) {
	        return false;
	    }
	}

}

