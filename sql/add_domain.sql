/* 添加域名 */
create procedure add_domain
(
	in user_id int unsigned,							/* 所属用户的ID */
	in domain nvarchar(255),							/* 加速域名 */
	in cname nvarchar(255),								/* cname, 规范名字 */
	in domain_type varchar(16),							/* 域名类型：image-图片，file-文件，web-网页，video-视频 */
	in origin_type varchar(16),							/* 源站类型：domain-域名类型 IP-IP类型 */
	in origin_domain nvarchar(255),						/* 回源时使用的域名 */
	in origin_ip varchar(32),							/* 回源时使用的IP */
	in expire_default int unsigned,						/* 默认过期时间，当源站没有过期时间时生效 */
	in expire_force int unsigned, 						/* 强制过期时间，将覆盖源站的过期时间 */
	in status varchar(8),								/* 启用状态：on-启用，off-禁用 */
	in remark nvarchar(64)								/* 备注 */
)
begin
	/* 插入数据 */
	insert ignore into domain(user_id, domain, cname, domain_type, origin_type, origin_domain, origin_ip, expire_default, expire_force, status, remark, create_time) values(user_id, domain, cname, domain_type, origin_type, origin_domain, origin_ip, expire_default, expire_force, status, remark, now());
	/* 放入结果集 */
	select last_insert_id() as domain_id, row_count() as row_count, now() as create_time, if(row_count() > 0, '操作成功！', '操作失败，该域名已存在。') as message;
end 

