#include "header.h"

char *get_base(char *file_data)
{
    int i;
    int j;
    char *base;

    base = (char*)malloc(4 * sizeof(char));
    if(!base)
        return (0);
    i = -1;
    j = -1;
    while (file_data[++i] != '\n')
    {
        if (!(file_data[i] >= '0' && file_data[i] <= '9') && file_data[i] != ' ')
            base[++j] = file_data[i];
    }
    return (base);
}