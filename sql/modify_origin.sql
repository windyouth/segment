/* 修改回源信息 */
create procedure modify_origin 
(
 	in arg_domain nvarchar(255),							/* 域名 */
	in arg_user_id int unsigned,							/* 用户ID */
	in arg_origin_type varchar(16),							/* 源站类型：domain-域名类型 IP-IP类型 */
	in arg_origin_domain nvarchar(255),						/* 回源时使用的域名 */
	in arg_origin_ip varchar(32)							/* 回源时使用的IP */
)
begin
	update domain set origin_type = arg_origin_type, origin_domain = arg_origin_domain, origin_ip = arg_origin_ip
		where domain = arg_domain and user_id = arg_user_id;
	select row_count() as row_count, if(row_count() > 0, '操作成功！', '操作失败，请检查各参数是否正确。') as message;
end 

