/* 查询用户信息 */
drop procedure if exists `query_user`;
create procedure query_user
(
	in arg_account varchar(32), 						/* 用户名 */
	in arg_password varchar(32)							/* 密码 */
)
begin
	select id, account, secret_key, corporation, phone from user where account = arg_account and password = arg_password;
end
