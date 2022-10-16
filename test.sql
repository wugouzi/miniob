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
create table t(id int, age int);
insert into t values(1,1);
insert into t values(2,2);
insert into t values(3,3);
select max(age) from t;
select count(*) from t;
select count(1) from t;
select count(id) from t;

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
