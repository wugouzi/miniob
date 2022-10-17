/* aggregate */
create table t(id int,name char(4),da date);
insert into t values(1,'lige','2021-10-30');
insert into t values(11,'lige','2021-10-31');
insert into t values(2,'aset','2000-2-29');
insert into t values(4,'deft','1976-2-29');
insert into t values(5,'ghit','2035-1-1');
insert into t values(6,'jklt','2021-6-30');
insert into t values(233,'nowt','2021-10-31');
select count(1),avg(id) from t;
select count(*),max(id),min(da),avg(id) from t where t.id<233;
select max(id),min(da),avg(id) from t where t.id<233;
select count(1),count(2),count(id),count(*),max(da),min(da) from t;
select count() from t;
select count(id,name) from t;
select count(hh) from t;
select count(*),count(hh) from t;
select max(id),count(id,name) from t;
drop table t;
exit;

select count(id,name) from t;

create table t(id int,name char(4),da date);
insert into t values(1,'lige','2021-10-30');
insert into t values(11,'lige','2021-10-31');
insert into t values(2,'aset','2000-2-29');
insert into t values(4,'deft','1976-2-29');
insert into t values(5,'ghit','2035-1-1');
insert into t values(6,'jklt','2021-6-30');
insert into t values(233,'nowt','2021-10-31');
create table s(id int,name char(4),da date);
insert into s values(7,'lige','2021-10-30');
insert into s values(8,'lige','2021-10-31');
insert into s values(9,'aset','2000-2-29');
insert into s values(10,'deft','1976-2-29');
insert into s values(11,'ghit','2035-1-1');
insert into s values(12,'jklt','2021-6-30');
insert into s values(233,'nowt','2021-10-31');
select s.name from s,t where s.name=t.name;
select s.name,t.id,t.name from s,t where s.id=t.id;
select * from s,t where s.name=t.name;
select * from s,t where s.id=t.id and s.da>'2021-10-30' and t.da<'2021-10-31' and t.id>1;
select * from s,t where s.id=t.id;
select * from s,t where s.id=t.id and t.da>'2021-10-30';
drop table t;
drop table s;
exit;

/* update */

create table t(id int,name char,da date);
create index da_t on t(da);
insert into t values(1,'ligen','2021-10-30');
insert into t values(11,'ligen','2021-10-31');
insert into t values(2,'aset','2000-2-29');
insert into t values(4,'deft','1976-2-29');
insert into t values(5,'ghit','2035-1-1');
insert into t values(6,'jklt','2021-6-30');
insert into t values(233,'nowt','2021-10-31');
select * from t;
update t set name='aaa' where da='2021-10-31';
select * from t;
update t set name='bbb' where da='2021-10-32';
select * from t;
update t set name='ccc' where id=9;
select * from t;
update t set name="OK" where da>='1976-2-29';
select * from t;
drop table t;
exit;


/* drop table */
create table Drop_table_6(id int);
DROP TABLE Drop_table_6;
select * from Drop_table_6;
SELECT * FROM DROP_TABLE_6;



/* multi_table */
drop table t1;
drop table t2;
drop table t3;
create table t1(id int, age int);
create table t2(c char);
create table t3(id int);
insert into t1 values(1, 3);
insert into t2 values("A");
insert into t3 values(2);
insert into t1 values(2, 2);
insert into t2 values("B");
insert into t3 values(4);
select * from t1,t2,t3;


drop table t1;
drop table t2;
create table t1(id int, age int);
create table t2(id int, sb int);
insert into t1 values(1,1);
insert into t1 values(2,2);
insert into t2 values(1,2);
insert into t2 values(2,4);
select * from t1,t2 where t1.id=t2.id and t1.age=1;
select * from t1,t2;
select * from t1,t2,t3;

drop table t;
create table t(id int, age int);
insert into t values(1,1);
insert into t values(2,2);
insert into t values(3,3);
select * from t;
select * from t where name='a';
select address from t where id=1;
select * from t_1000;
select * from t where not_exists_col=1;

/*
COUNT(*) counts all rows
COUNT(column) counts non-NULLs only
*/
drop table t;
create table t(id int, age int);
insert into t values(1,1);
insert into t values(2,2);
insert into t values(3,4);
select min(age) from t;
select count(1) from t;
select count(*) from t;
select max(age) from t;
select avg(age) from t;
select count(id) from t;
select avg(age), max(age) from t;

/* dates */
drop table t;
create table t(id int, birthday date);
insert into t values(1, '2020-09-10');
insert into t values(2, '2021-1-2');
select * from t where birthday > '2010-10-01';
select * from t where birthday > '2020-10-01';
select * from t where birthday < '2020-10-01';
select * from t;


drop table t;
create table t(id int, birthday char);
insert into t values(1, 'wefwef');
insert into t values(2, '2wefwe');
select * from t;

/* complex */
drop table t1;
drop table t2;
create table t1(id int, age int);
create table t2(id int, sb int);
insert into t1 values(1,1);
insert into t1 values(2,2);
insert into t2 values(11,12);
insert into t2 values(12,14);
update t2 set sb=100 where id=12;
select * from t1,t2 where t1.id=t2.id and t1.age=1;
select * from t1,t2;


/* update */
drop table t;
create table t(id int, age int);
insert into t values(1,1);
update t set id='2' where age=1;
update t set id=2 where g=3;
update t set g=3 where id=1;



/* multi multi */
drop table t1;
drop table t2;
drop table t3;
create table t1(id int, age int);
create table t2(id int, c char);
create table t3(id int, d date);
insert into t1 values(1, 1);
insert into t1 values(2, 2);
insert into t1 values(3, 3);
insert into t1 values(4, 4);
insert into t1 values(5, 5);
insert into t2 values(1, 'A');
insert into t2 values(2, 'B');
insert into t2 values(3, 'C');
insert into t2 values(4, 'D');
insert into t3 values(1, '1666-10-1');
insert into t3 values(2, '2000-10-1');
insert into t3 values(3, '2001-10-1');
insert into t3 values(4, '2004-10-1');
insert into t3 values(5, '1555-10-1');
insert into t3 values(6, '2333-10-1');
select * from t1,t2,t3 where t1.id=t2.id and t2.id=t3.id;
select * from t2,t3 where t2.id=t3.id;
select * from t1,t2,t3 where t1.id=t2.id;

--another multi
drop table t1;
drop table t2;
create table t1(a int, b float, c char, d date);
create table t2(a int, b float, c char, d date);
insert into t1 values(1, 1.1, 'lyq', '2020-10-22');
insert into t1 values(11.1, 111, 'com', '2020-10-9');
insert into t2 values(2, 2.2, 'lhc', '2000-1-22');
insert into t2 values(22, 22.22, 'com', '2000-1-1');
insert into t2 values(22.2, 222, 'cn', '2000-12-12');
select t1.a, t2.b, t1.c, t2.d from t1, t2;
select t1.a, t1.*, t2.*, *, t1.a, *, t2.b from t1, t2;
select * from t2, t1;
select a, b, c, d from t1, t2;
select t3.a, t1.b, t4.c, t2.d from t1, t2;
select t3.* from t1, t2;
select t1.a, t1.b, t2.c, t2.d from t1, t2 where t1.a > t2.b and t1.a < 100000 and t2.b < 30000;
