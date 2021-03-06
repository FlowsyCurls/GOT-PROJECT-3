CREATE PROCEDURE `repositoryAddOrEdit` (
  IN _id INT,
  IN _name VARCHAR(45)
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
END$$

DELIMITER ;

