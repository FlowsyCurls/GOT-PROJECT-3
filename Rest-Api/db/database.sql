CREATE DATABASE IF NOT EXISTS got;

USE got;

CREATE TABLE repository (
  id INT(11) NOT NULL AUTO_INCREMENT,
  name VARCHAR(45) DEFAULT NULL,
  PRIMARY KEY(id)
);

DESCRIBE repository;

INSERT INTO repository values 
  (1, 'Proyecto_1'),
  (2, 'Proyecto_2'),
  (3, 'Proyecto_3');

SELECT * FROM repository;