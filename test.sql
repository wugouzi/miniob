-- drop table
-- -- echo 1. Drop empty table
CREATE TABLE Drop_table_1(id int, t_name char);
DROP TABLE Drop_table_1;
CREATE TABLE Drop_table_2(id int, t_name char);
INSERT INTO Drop_table_2 VALUES (1,'OB');
DROP TABLE Drop_table_2;
CREATE TABLE Drop_table_3(id int, t_name char);
INSERT INTO Drop_table_3 VALUES (1,'OB');
DROP TABLE Drop_table_3;
INSERT INTO Drop_table_3 VALUES (1,'OB');
SELECT * FROM Drop_table_3;
DELETE FROM Drop_table_3 WHERE id = 3;
CREATE TABLE Drop_table_3(id int, t_name char);
CREATE TABLE Drop_table_4(id int, t_name char);
DROP TABLE Drop_table_4;
DROP TABLE Drop_table_4;
DROP TABLE Drop_table_4_1;
CREATE TABLE Drop_table_5(id int, t_name char);
DROP TABLE Drop_table_5;
CREATE TABLE Drop_table_5(id int, t_name char);
SELECT * FROM Drop_table_5;
CREATE TABLE Drop_table_6(id int, t_name char);
CREATE INDEX index_id on Drop_table_6(id);
INSERT INTO Drop_table_6 VALUES (1,'OB');
DROP TABLE Drop_table_6;
SELECT * FROM Drop_table_6;


-- meta
create table t(id int, age int);
insert into t values(1,1);
insert into t values(2,2);
select *, * from t1;
select *,id from t1;
select *,age from t1;
select *,age from t1;