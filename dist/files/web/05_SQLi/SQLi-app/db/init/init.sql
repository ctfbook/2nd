
create database if not exists db;

use db;


create table if not exists kv(
	id int not null auto_increment,
	k char(255) unique,
	v text,
	primary key (id)
);


create table if not exists secrets(
	id int not null auto_increment,
   	data text,
	primary key(id)
);

insert into secrets(data) values('flag{can_you_get_me?}');
insert into kv(k, v) values('key1', 'value1');


