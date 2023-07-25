#include "header.h"

int bsq(int arg_number, char **src)
{
    int i;

    i = 0;
    while (++i < arg_number)
    {
        if (!read_file(src[i]))
            write(1, "Error!\n", 7);
        if(arg_number > 2 && i < arg_number - 1)
            write(1, "\n", 1);

    }
    return (1);
}