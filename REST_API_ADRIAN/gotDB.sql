Drop Database db_got;
CREATE DATABASE db_got;

use db_got;

create table repositories
(
    id int auto_increment
        primary key,
    name varchar(45) not null
);

create table commits
(
    idCommit int auto_increment
        primary key,
    message varchar(100) not null,
    date varchar(100) not null,
    idRepository int not null
);

create table files
(
    idFile int auto_increment
        primary key,
    content varchar(10000) not null,
    date varchar(100) not null,
    idCommit int not null
);


Insert into repositories values
    (1,"P1"),
    (2,"P2"),
    (3,"P3"),
    (4,"P4");

Insert into commits values
    (1,"Hola", "2023-01-21", 1),
    (2,"Soy", "2020-08-14", 2),
    (3,"Shakime", "2020-08-14", 3),
    (4,"LULU", "2020-08-14", 3);

Insert into files values
    (1,"01010101", "2023-01-21", 1),
    (2,"01010101","2023-01-21", 2),
    (3,"01010101", "2023-01-21", 2),
    (4,"01010101", "2023-01-21", 4);