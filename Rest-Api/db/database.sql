CREATE DATABASE IF NOT EXISTS got;
USE got;

CREATE TABLE `Commit` (
  `ID` int not null auto_increment,
  `Message` varchar(20) not null,
  `Date` datetime default null,
  PRIMARY KEY (`ID`)
);

CREATE TABLE `Repository` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `Name` VARCHAR(20) DEFAULT NULL,
  PRIMARY KEY (`ID`)
);

CREATE TABLE `File` (
  `ID` int not null auto_increment,
  `Path` varchar(124) default null,
  `Name` varchar(20) not null,
  `Data` text,
  `RepositoryID` int default null,
  `CommitID` int default null,
  PRIMARY KEY (`ID`),
  CONSTRAINT `CommitID` FOREIGN KEY (`CommitID`) REFERENCES `Commit` (`ID`),
  CONSTRAINT `RepositoryID` FOREIGN KEY (`RepositoryID`) REFERENCES `Repository` (`ID`)
);


INSERT INTO `Repository` values 
  (1, 'Proyecto_1'),
  (2, 'Proyecto_2'),
  (3, 'Proyecto_3');

INSERT INTO `Commit` values 
  (1, 'Se agrega readme.md','2015-11-05 14:29:36'),
  (2, 'Se agrega gitignore.','2023-01-21 09:20:00'),
  (3, 'Se arreglan buggs','2000-10-31 15:50:15');
  
INSERT INTO `File` values 
  (1, '/home/jeykime/Documents','GOT','01010101',1,1),
  (1, '/home/adrian/Downloads','AIRWAR','01010101',2,3),
  (1, '/home/shakime/Desktop','SCRABBLE','01010101',1,2);

SELECT * FROM File INNER JOIN Commit on Commit.ID = CURSO.Escuela INNER JOIN PROFESOR  on CURSO.Profesor = PROFESOR.ID;