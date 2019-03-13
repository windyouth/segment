#include <stdio.h>
#include "algorithm.h"

void main()
{
    char hex[32];
    snprintf(hex, 32, "%s", "0522-38AB-DF6C");

    char out[8] = { 0 };

    hex_to_int(hex, strlen(hex), out, 6);
    printf("%lx \n", *((long *)out));
}
