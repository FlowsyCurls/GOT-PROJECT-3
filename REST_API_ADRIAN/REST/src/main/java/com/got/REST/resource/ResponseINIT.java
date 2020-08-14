package com.got.REST.resource;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import com.got.REST.model.Usuario;

@Path("/init")
public class ResponseINIT {
	
	@GET
	@Path("/algo")
	@Consumes({MediaType.APPLICATION_JSON})
	@Produces({MediaType.APPLICATION_JSON})
	public Usuario user(Usuario vo) {
		Usuario u = new Usuario();
		u.setId(1);
		u.setNombre("adrian");
		return u;
	}

}
