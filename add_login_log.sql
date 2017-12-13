/* 添加日志记录 */
drop procedure if exists `add_login_log`;
create procedure add_login_log
(
	in arg_uuid varchar(64),				/* 用户uuid */
	in arg_addr varchar(16)					/* ip地址 */
)
begin
	insert ignore into login_log(xc_uid, ip_addr) values(arg_uuid, arg_addr);	
end
