/* 创建登录日志记录表 */
drop table if exists `login_log`;
create table login_log
(
	xc_uid varchar(64) not null,							/* 用户uuid */
	ip_addr varchar(16) not null							/* 用户登录的IP地址 */
)engine=MyISAM auto_increment=1 default charset=utf8;
/* 添加主键约束 */
alter table login_log add primary key(xc_uid, ip_addr);
