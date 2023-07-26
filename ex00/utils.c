#include "header.h"

int get_base(char *file_data, char *base)
{
    int i;
    int j;
    int len;

    i = -1;
    j = -1;
    len = 1;
    if(file_data[0] == '0')
        return (0);
    while (file_data[++i] != '\n')
    {   
        len++;
        if(!(file_data[i] >= '0' && file_data[i] <= '9') && j < 3)
            base[++j] = file_data[i];
    }
    return (len);
}