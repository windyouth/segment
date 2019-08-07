#include <stdio.h>

//执行shell命令，带输出
int exec_cmd(const char *cmd, char **out, int *out_len)
{
    //变量定义
    char temp[1024];
    int temp_len = 0, read = 0;
    *out_len = 0;

    //参数检查
    if (!cmd || !out || !out_len) return -1;

    //执行命令
    FILE *file = popen(cmd, "r");    
    if (!file) return -2;

    //循环读取数据
    while (fgets(temp, sizeof(temp), file))
    {
        //计算并申请内存
        temp_len = strlen(temp);
        *out_len += temp_len;
        *out = realloc(*out, *out_len + 1);
        if (*out == NULL)
            return -3;

        //拷贝
        memcpy(*out + read, temp, temp_len);
        read += temp_len;
    }

    //去掉末尾的换行符
    (*out)[*out_len - 1] = 0;

    fclose(file);
    return 0;
}

//查看CPU核数
int get_cpu_cores()
{
    char *out = 0;
    int out_len, num = 0;
    char *cmd = "cat /proc/cpuinfo | grep processor | wc -l";

    //执行shell命令
    exec_cmd(cmd, &out, &out_len);
    if (!out) return -1;

    num = atoi(out);
    free(out);

    return num;
}
