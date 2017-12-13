/* 创建域名表 */
create table domain
(
	id int unsigned not null auto_increment primary key,		/* 域名ID */
	user_id int unsigned not null,								/* 所属用户的ID */
	domain nvarchar(255) not null,								/* 加速域名 */
	cname nvarchar(255) not null,								/* cname, 规范名字 */
	domain_type varchar(16) not null, 							/* 域名类型：image-图片，file-文件，web-网页，video-视频 */
	origin_type varchar(16) not null,							/* 源站类型：domain-域名类型 IP-IP类型 */
	origin_domain nvarchar(255),								/* 回源时使用的域名 */
	origin_ip varchar(160),										/* 回源时使用的IP */
	expire_default int unsigned,								/* 默认过期时间，当源站没有过期时间时生效 */
	expire_force int unsigned, 									/* 强制过期时间，将覆盖源站的过期时间 */
	status varchar(8) default "off",							/* 启用状态：on-启用，off-禁用 */
	remark nvarchar(64),										/* 备注 */
	create_time datetime not null,								/* 创建时间 */
	last_modify_time timestamp									/* 最后一次修改时间 */
)engine=MyISAM auto_increment=1001 default charset=utf8;
/* 添加唯一约束 */
alter table domain add unique(domain);
alter table domain add unique(cname);

