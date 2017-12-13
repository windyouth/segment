/* 查询域名列表 */
create procedure query_domains_list 
(
	in arg_user_id int unsigned								/* 用户ID */
)
begin
	select id, domain, cname, domain_type, origin_type, origin_domain, origin_ip, expire_default as expire, status,
	    remark, create_time, modify_time from domain where user_id = arg_user_id;
end 

