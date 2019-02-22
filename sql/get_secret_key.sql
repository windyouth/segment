
/* 查询用户密钥 */
create procedure get_secret_key
(
	in user_id int								/* 用户ID */
)
BEGIN
	/* 查询数据 */
	select secret_key from user where id = user_id;
END  

