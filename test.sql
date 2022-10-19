--typecast
create table t(id int);
insert into t values('2');
select * from t;
update t set id=1.1;
update t set id='33';
select * from t where id='3';
create table t(id int, name char, year float);
insert into t values(1,'a',12);
select * from t where id='1a';
select * from t where id='a';
select * from t where id>='1a';
drop table t;

--selects
CREATE TABLE Select_tables_1(id int, age int, u_name char);
CREATE TABLE Select_tables_2(id int, age int, u_name char);
CREATE TABLE Select_tables_3(id int, res int, u_name char);
CREATE TABLE Select_tables_4(id int, age int, u_name char);
CREATE TABLE Select_tables_5(id int, res int, u_name char);

INSERT INTO Select_tables_1 VALUES (1,18,'a');
INSERT INTO Select_tables_1 VALUES (2,15,'b');
INSERT INTO Select_tables_2 VALUES (1,20,'a');
INSERT INTO Select_tables_2 VALUES (2,21,'c');
INSERT INTO Select_tables_3 VALUES (1,35,'a');
INSERT INTO Select_tables_3 VALUES (2,37,'a');
INSERT INTO Select_tables_4 VALUES (1, 2, 'a');
INSERT INTO Select_tables_4 VALUES (1, 3, 'b');
INSERT INTO Select_tables_4 VALUES (2, 2, 'c');
INSERT INTO Select_tables_4 VALUES (2, 4, 'd');
INSERT INTO Select_tables_5 VALUES (1, 10, 'g');
INSERT INTO Select_tables_5 VALUES (1, 11, 'f');
INSERT INTO Select_tables_5 VALUES (2, 12, 'c');

SELECT * FROM Select_tables_1,Select_tables_2,Select_tables_3;
SELECT Select_tables_1.id,Select_tables_2.u_name,Select_tables_3.res FROM Select_tables_1,Select_tables_2,Select_tables_3;
Select Select_tables_1.res FROM Select_tables_1,Select_tables_2,Select_tables_3;
SELECT * FROM Select_tables_1,Select_tables_2,Select_tables_3 WHERE Select_tables_1.u_name=Select_tables_2.u_name AND Select_tables_2.u_name=Select_tables_3.u_name;
SELECT * FROM Select_tables_1,Select_tables_2,Select_tables_3 WHERE Select_tables_1.id=Select_tables_2.id AND Select_tables_3.res=35;
SELECT * FROM Select_tables_1,Select_tables_2,Select_tables_3 WHERE Select_tables_1.age<18 AND Select_tables_2.u_name='c' AND Select_tables_3.res=35 AND Select_tables_1.id=Select_tables_2.id AND Select_tables_2.id=Select_tables_3.id;
SELECT Select_tables_2.age FROM Select_tables_1,Select_tables_2 WHERE Select_tables_1.age<18 AND Select_tables_2.u_name='c' AND Select_tables_1.id=Select_tables_2.id;
SELECT * from Select_tables_4, Select_tables_5 where Select_tables_4.id=Select_tables_5.id;
select * from Select_tables_4, Select_tables_5 where Select_tables_4.id >= Select_tables_5.id;
CREATE TABLE Select_tables_6(id int, res int);

SELECT Select_tables_1.id,Select_tables_6.id from Select_tables_1, Select_tables_6 where Select_tables_1.id=Select_tables_6.id;

drop table Select_tables_1;
drop table Select_tables_2;
drop table Select_tables_3;
drop table Select_tables_4;
drop table Select_tables_5;
drop table Select_tables_6;

/*
1 | 18 | A | 1 | 20 | A | 1 | 35 | A
1 | 18 | A | 1 | 20 | A | 2 | 37 | A
1 | 18 | A | 2 | 21 | C | 1 | 35 | A
1 | 18 | A | 2 | 21 | C | 2 | 37 | A
2 | 15 | B | 1 | 20 | A | 1 | 35 | A
2 | 15 | B | 1 | 20 | A | 2 | 37 | A
2 | 15 | B | 2 | 21 | C | 1 | 35 | A
2 | 15 | B | 2 | 21 | C | 2 | 37 | A
SELECT_TABLES_1.ID | SELECT_TABLES_1.AGE | SELECT_TABLES_1.U_NAME | SELECT_TABLES_2.ID | SELECT_TABLES_2.AGE | SELECT_TABLES_2.U_NAME | SELECT_TABLES_3.ID | SELECT_TABLES_3.RES | SELECT_TABLES_3.U_NAME

1 | A | 35
1 | A | 37
1 | C | 35
1 | C | 37
2 | A | 35
2 | A | 37
2 | C | 35
2 | C | 37
SELECT_TABLES_1.ID | SELECT_TABLES_2.U_NAME | SELECT_TABLES_3.RES

FAILURE

1 | 18 | A | 1 | 20 | A | 1 | 35 | A
1 | 18 | A | 1 | 20 | A | 2 | 37 | A
SELECT_TABLES_1.ID | SELECT_TABLES_1.AGE | SELECT_TABLES_1.U_NAME | SELECT_TABLES_2.ID | SELECT_TABLES_2.AGE | SELECT_TABLES_2.U_NAME | SELECT_TABLES_3.ID | SELECT_TABLES_3.RES | SELECT_TABLES_3.U_NAME

1 | 18 | A | 1 | 20 | A | 1 | 35 | A
2 | 15 | B | 2 | 21 | C | 1 | 35 | A
SELECT_TABLES_1.ID | SELECT_TABLES_1.AGE | SELECT_TABLES_1.U_NAME | SELECT_TABLES_2.ID | SELECT_TABLES_2.AGE | SELECT_TABLES_2.U_NAME | SELECT_TABLES_3.ID | SELECT_TABLES_3.RES | SELECT_TABLES_3.U_NAME

21
SELECT_TABLES_2.AGE

1 | 2 | A | 1 | 10 | G
1 | 2 | A | 1 | 11 | F
1 | 3 | B | 1 | 10 | G
1 | 3 | B | 1 | 11 | F
2 | 2 | C | 2 | 12 | C
2 | 4 | D | 2 | 12 | C
SELECT_TABLES_4.ID | SELECT_TABLES_4.AGE | SELECT_TABLES_4.U_NAME | SELECT_TABLES_5.ID | SELECT_TABLES_5.RES | SELECT_TABLES_5.U_NAME

1 | 2 | A | 1 | 10 | G
1 | 2 | A | 1 | 11 | F
1 | 3 | B | 1 | 10 | G
1 | 3 | B | 1 | 11 | F
2 | 2 | C | 1 | 10 | G
2 | 2 | C | 1 | 11 | F
2 | 2 | C | 2 | 12 | C
2 | 4 | D | 1 | 10 | G
2 | 4 | D | 1 | 11 | F
2 | 4 | D | 2 | 12 | C
SELECT_TABLES_4.ID | SELECT_TABLES_4.AGE | SELECT_TABLES_4.U_NAME | SELECT_TABLES_5.ID | SELECT_TABLES_5.RES | SELECT_TABLES_5.U_NAME

SUCCESS

SELECT_TABLES_1.ID | SELECT_TABLES_6.ID

*/


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

CREATE TABLE Update_table_1(id int, t_name char(4), col1 int, col2 int);
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
SELECT * FROM Update_table_1;
drop table Update_table_1;
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
