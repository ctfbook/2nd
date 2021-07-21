CREATE DATABASE IF NOT EXISTS db;

use db;

CREATE TABLE IF NOT EXISTS fruits(
	id INT NOT NULL AUTO_INCREMENT,
	name TEXT,
	PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS price_fruits(
	id INT NOT NULL AUTO_INCREMENT,
	fruit_id INT,
	price INT,
	PRIMARY KEY (id),
	FOREIGN KEY (fruit_id) REFERENCES fruits(id) ON DELETE CASCADE
);


INSERT INTO fruits(id, name) VALUES(1, 'mandarin');
INSERT INTO fruits(id, name) VALUES(2, 'strawberry');
INSERT INTO fruits(id, name) VALUES(3, 'melon');

INSERT INTO price_fruits(id, fruit_id, price) VALUES(1, 1, 100);
INSERT INTO price_fruits(id, fruit_id, price) VALUES(2, 2, 200);
INSERT INTO price_fruits(id, fruit_id, price) VALUES(3, 3, 1000);


