/* 设置域名状态 */
create procedure set_domain_status 
(
 	in arg_domain nvarchar(255),						/* 域名 */
	in arg_user_id int unsigned,						/* 用户ID */
	in arg_status varchar(8)							/* 启用状态：on-启用，off-禁用 */
)
begin
	declare name nvarchar(255);
	declare tmp_status enum('on', 'off');

	select cname into name from domain where domain = arg_domain and user_id = arg_user_id;
	select status into tmp_status from domain where domain = arg_domain and user_id = arg_user_id;
	/* 更新状态 */
	update domain set status = arg_status where domain = arg_domain and user_id = arg_user_id;
	select row_count() as row_count, if(arg_status = tmp_status, '该域名已经是此状态，不需要重复设置。', '请检查各参数是否正确。') as message, name;
end 

