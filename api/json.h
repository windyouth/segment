#ifndef _JSON_H_
#define _JSON_H_

typedef cJSON json;

//将字符串解析成json对象
JSON_API json *json_parse(const char *text);
//将json对象序列化成字符串
JSON_API char *json_print(json *json);
//从json文件中读取内容
JSON_API json *json_file(const char *path);
//将json对象保存到文件
JSON_API void json_save(json *json, const char *path);
//创建json对象
JSON_API json *json_create();
//销毁json对象
JSON_API void json_destroy(json *json);
//释放内存，如果是调用动态库
//json_print打印的字符串指针用完后建议采用此函数释放.
JSON_API void json_free(void *buf);

//向json中添加int值
JSON_API void json_add_int(json *json, const char *key, int value); 
//向json中添加double值
JSON_API void json_add_double(json *json, const char *key, double value); 
//向json中添加bool值
JSON_API void json_add_bool(json *json, const char *key, int value); 
//向json中添加字符串
JSON_API void json_add_string(json *json, const char *key, const char *value); 
//向json中添加对象
JSON_API void json_add_item(json *json, const char *key, json *item); 

//从json中读取int值
JSON_API int json_value_int(json *json, const char *key);
//从json中读取double值
JSON_API double json_value_double(json *json, const char *key);
//从json中读取bool值：true 返回1，false 返回0
JSON_API int json_value_bool(json *json, const char *key);
//从json中读取字符串
JSON_API char *json_value_string(json *json, const char *key);
//从json中读取对象
JSON_API json *json_value_item(json *json, const char *key);

#endif //_JSON_H_
