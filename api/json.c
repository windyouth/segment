#include <stdio.h>
#include "json.h"

//从json文件中读取内容
JSON_API json *json_file(const char *path)
{
    FILE *file;
    long len;
    char *data;

    file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    //取得文件位置指针当前位置相对于文件首的偏移字节数。
    len = ftell(file);
    //跳到文件开头
    fseek(file, 0, SEEK_SET);
    data = (char *)malloc(len + 1);
    //读文件内容到内存
    fread(data, 1, len, file);
    data[len] = 0;
    fclose(file);

    json *json = json_parse(data);
    free(data);

    return json;
}

//将json对象保存到文件
JSON_API void json_save(json *json, const char *path)
{
    char *text = json_print(json);
    if (!text) return;

    FILE *file = fopen(path, "w");
    fseek(file, 0, SEEK_SET);
    fwrite(text, 1, strlen(text), file);
    fclose(file);
    free(text);
}
