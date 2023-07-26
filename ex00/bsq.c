#include "header.h"

int bsq(int arg_number, char **src)
{
    int i;
    int err;
    char c;
    char src_s[255];
    int len;

    len = 0;
    if (arg_number == 1)
    {
        while ((c = my_getchar()) != '\n' && c != EOF && len < 255 - 1)
            src_s[len++] = c;
        src_s[len] = 0;
        err = read_file(src_s);
        if (err == 1)
             write(1, "Error!\n", 7);
        else if (err == 2)
             write(1, "map error!\n", 11);
    }
    i = 0;
    while (++i < arg_number)
    {
        err = read_file(src[i]);
        if (err == 1)
             write(1, "Error!\n", 7);
        else if (err == 2)
             write(1, "map error!\n", 11);
        if(arg_number > 2 && i < arg_number -1)
             write(1, "\n", 1);

    }
    return (1);
}