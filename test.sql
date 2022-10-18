CREATE TABLE date_table(id int, u_date date);
SELECT * FROM date_table WHERE u_date='2017-2-29';
--date
CREATE TABLE date_table(id int, u_date date);
CREATE INDEX index_id on date_table(u_date);

INSERT INTO date_table VALUES (1,'2020-01-21');
INSERT INTO date_table VALUES (2,'2020-10-21');
INSERT INTO date_table VALUES (3,'2020-1-01');
INSERT INTO date_table VALUES (4,'2020-01-1');
INSERT INTO date_table VALUES (5,'2019-12-21');
INSERT INTO date_table VALUES (6,'2016-2-29');
INSERT INTO date_table VALUES (7,'1970-1-1');
INSERT INTO date_table VALUES (8,'2000-01-01');
INSERT INTO date_table VALUES (9,'2038-1-19');

SELECT * FROM date_table WHERE u_date>'2020-1-20';
SELECT * FROM date_table WHERE u_date<'2019-12-31';
SELECT * FROM date_table WHERE u_date='2020-1-1';

DELETE FROM date_table WHERE u_date>'2012-2-29';
SELECT * FROM date_table;

SELECT * FROM date_table WHERE u_date='2017-2-29';
SELECT * FROM date_table WHERE u_date='2017-21-29';
SELECT * FROM date_table WHERE u_date='2017-12-32';
SELECT * FROM date_table WHERE u_date='2017-11-31';

INSERT INTO date_table VALUES (10,'2017-2-29');
INSERT INTO date_table VALUES (11,'2017-21-29');
INSERT INTO date_table VALUES (12,'2017-12-32');
INSERT INTO date_table VALUES (13,'2017-11-31');
drop table date_table;

/*
1 | 2020-01-21
2 | 2020-10-21
9 | 2038-01-19
ID | U_DATE

5 | 2019-12-21
6 | 2016-02-29
7 | 1970-01-01
8 | 2000-01-01
ID | U_DATE

3 | 2020-01-01
4 | 2020-01-01
ID | U_DATE

DELETE
SUCCESS

7 | 1970-01-01
8 | 2000-01-01
ID | U_DATE
*/

--update

CREATE TABLE Update_table_1(id int, t_name char, col1 int, col2 int);
CREATE INDEX index_id on Update_table_1(id);
INSERT INTO Update_table_1 VALUES (1,'N1',1,1);
INSERT INTO Update_table_1 VALUES (2,'N2',1,1);
INSERT INTO Update_table_1 VALUES (3,'N3',2,1);
UPDATE Update_table_1 SET t_name='N01' WHERE id=1;
SELECT * FROM Update_table_1;
UPDATE Update_table_1 SET col2=0 WHERE col1=1;
SELECT * FROM Update_table_1;
UPDATE Update_table_1 SET id=4 WHERE t_name='N3';
SELECT * FROM Update_table_1;
UPDATE Update_table_1 SET col1=0;
SELECT * FROM Update_table_1;
UPDATE Update_table_1 SET t_name='N02' WHERE col1=0 AND col2=0;
SELECT * FROM Update_table_1;
UPDATE Update_table_2 SET t_name='N01' WHERE id=1;
UPDATE Update_table_1 SET t_name_false='N01' WHERE id=1;
UPDATE Update_table_1 SET t_name='N01' WHERE id_false=1;
UPDATE Update_table_1 SET t_name='N01' WHERE id=100;
SELECT * FROM Update_table_1;
UPDATE Update_table_1 SET col1='N01' WHERE id=1;

/*
SUCCESS
SUCCESS
SUCCESS
SUCCESS
SUCCESS

SUCCESS
1 | N01 | 1 | 1
2 | N2 | 1 | 1
3 | N3 | 2 | 1
ID | T_NAME | COL1 | COL2

SUCCESS
1 | N01 | 1 | 0
2 | N2 | 1 | 0
3 | N3 | 2 | 1
ID | T_NAME | COL1 | COL2

SUCCESS
1 | N01 | 1 | 0
2 | N2 | 1 | 0
4 | N3 | 2 | 1
ID | T_NAME | COL1 | COL2

SUCCESS
1 | N01 | 0 | 0
2 | N2 | 0 | 0
4 | N3 | 0 | 1
ID | T_NAME | COL1 | COL2

SUCCESS
1 | N02 | 0 | 0
2 | N02 | 0 | 0
4 | N3 | 0 | 1
ID | T_NAME | COL1 | COL2

FAILURE
FAILURE
FAILURE

SUCCESS
SELECT * FROM Update_table_1;
1 | N02 | 0 | 0
2 | N02 | 0 | 0
4 | N3 | 0 | 1
ID | T_NAME | COL1 | COL2


FAILURE
*/

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
delete from t where id=1;
delete from t where age=3;
drop table t;
insert into t values(1,1);
insert into t values(2,2);
select *, * from t1;
select *,id from t1;
select *,age from t1;
select *,age,id,age,id,* from t1;
