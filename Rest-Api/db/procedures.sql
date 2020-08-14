<<<<<<< HEAD
CREATE DATABASE IF NOT EXISTS got;

USE got;

CREATE TABLE repository (
  id INT(11) NOT NULL AUTO_INCREMENT,
  name VARCHAR(45) DEFAULT NULL,
  PRIMARY KEY(id)
);

DESCRIBE repository;

INSERT INTO employee values 
  (1, 'Proyecto_1'),
  (2, 'Proyecto_2'),
  (3, 'Proyecto_3';

SELECT * FROM repository;
=======
USE got;

DELIMITER $$
USE `got`$$

CREATE PROCEDURE `repositoryAddOrEdit` (
  IN _id INT,
  IN _name VARCHAR(45),
)
BEGIN 
  IF _id = 0 THEN
    INSERT INTO repository (name)
    VALUES (_name);

    SET _id = LAST_INSERT_ID();
  ELSE
    UPDATE repository
    SET
    name = _name
    WHERE id = _id;
  END IF;

  SELECT _id AS 'id';
END
>>>>>>> b413f87517cbbd576d3c7c813470c8b67e87fb6b
