/* 查询域名信息 */
create procedure query_domain
(
	in arg_domain nvarchar(255), 						/* 域名 */
	in arg_user_id int unsigned							/* 用户ID */
)
begin
	select id, domain, cname, domain_type, origin_type, origin_domain, origin_ip, expire_default as expire, status,
    	remark, create_time, modify_time from domain where domain = arg_domain and user_id = arg_user_id;
end 

