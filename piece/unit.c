#include <stdio.h>
#include "algorithm.h"
#include "tool.h"

void hex_test()
{
    char hex[32];
    snprintf(hex, 32, "%s", "0522-38AB-DF6C");

    char out[8] = { 0 };

    hex_to_int(hex, strlen(hex), out, 6);
    printf("%lx \n", *((long *)out));
}

void cmd_test()
{
    char *data = 0;
    int len = 0;
    int res = exec_cmd("cat tool.c", &data, &len);
    if (res != 0)
    {
        printf("exec_cmd failed, %d \n", res);
        return -1;
    }

    puts(data);
    free(data);
}

void realloc_test()
{
    char *str = 0;
    str = realloc(str, 16);
    snprintf(str, 16, "heihei");
    puts(str);
}

void main()
{
    cmd_test();
}
