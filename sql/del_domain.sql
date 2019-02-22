/* 删除域名 */
create procedure del_domain
(
 	in arg_domain nvarchar(255),						/* 域名 */
	in arg_user_id int unsigned							/* 用户ID */
)
begin
	declare name nvarchar(255);
	select cname into name from domain where domain = arg_domain and user_id = arg_user_id;
	/* 删除数据 */
	delete from domain where domain = arg_domain and user_id = arg_user_id;
	select row_count() as row_count, if(row_count() > 0, '删除成功！', '删除失败，请检查参数是否正确。') as message, name;
end 

