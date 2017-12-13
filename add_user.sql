
/* 注册账号 */
create procedure add_user
(
	in account varchar(32),								/* 用户名 */
	in password varchar(32),							/* 密码 */
	in secret_key varchar(32),							/* 用户密钥 */
	in corporation nvarchar(64),	 					/* 用户公司名 */
	in phone varchar(32)								/* 联系电话 */
)
BEGIN
	/* 插入数据 */
	insert ignore into user(account, password, secret_key, corporation, phone, create_time) values(account, password, secret_key, corporation, phone, now());
	/* 放入结果集 */
	select last_insert_id() as user_id, row_count() as row_count, if(row_count() > 0, '操作成功！', '操作失败，该用户名已存在。') as message;
END  

