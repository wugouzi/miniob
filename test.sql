create table t1 (a int, b date);
insert into t1 values(3,'2020-1-03');
insert into t1 values(4,'2020-01-03');
drop table t1;

insert into t1 values(1,'2020-1-3');
insert into t1 values(2,'2020-01-3');


insert into t1 values(5,'2020-02-3');
insert into t1 values(6, '2010-3-5');
insert into t1 values(7, '2000-3-5');
insert into t1 values(8, '1990-12-5');
insert into t1 values(9, '1980-2-5');
insert into t1 values(10, '1970-12-31');
select * from t1;
select * from t1 where b < '2020-3-4';
select b from t1 where b < '2020-3-4';
select * from t1 where b <= '2008-2-29';
select * from t1 where b > '2008-2-29';
select * from t1 where b >= '2008-2-29';
select * from t1 where b = '2008-2-29';
select * from t1 where b = '2000-3-5';
select b from t1 where b < '2021-2-29';
select b from t1 where b >= '2020-12-32';
delete from t1 where b = '1970-12-31';
select * from t1;
select * from t1;
select * from t1;



create table t7 (a int, b float, c char, d date);
create index c_id on t7 (c);
insert into t7 values(1,1.1,'a','2020-1-3');
drop table t7;

