
CREATE DATABASE IF NOT EXISTS db;

use db;


CREATE TABLE if not exists templates(
	id int NOT NULL AUTO_INCREMENT,
	name text,
	template text,
	PRIMARY KEY (id)
);

INSERT INTO templates(name, template) VALUES('test', 'test');
