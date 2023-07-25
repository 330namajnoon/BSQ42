#include "header.h"

int get_data_x_y(char *str, char c)
{
    int i;
    int res;

    i = -1;
    res = 0;
    if (c == 'x')
    {
        while (str[++i] != '\n')
            res++;
    }
    if (c == 'y')
    {
        while (str[++i] != '\0')
        {
            if(str[i] == '\n')
                res++;
        } 
        res++;
    }    
    return (res);
}

char **generate_table(char *str, int x, int y)
{
    int i;
    int j;
    int k;
    char **data;
    
    data = (char**)malloc(y * sizeof(char*));
    if (!data)
        return (0);
    i = -1;
    while (++i < y)
    {
        data[i] = (char*)malloc(x * sizeof(char));
        if (!data[i])
            return (0);
    }
    i = -1;
    j = 0;
    k = -1;
    while (str[++i] != '\0')
    {
        if(str[i] == '\n')
        {
            j++;
            k = -2;
        }
        data[j][++k] = str[i];
    }
    return (data);  
}

int get_file_data_len(char *src)
{
    int file;
    int len;
    char c;

    len = 0;
    file = open(src, O_RDONLY);
    if (file == -1)
        return (0);
    while (read(file , &c, sizeof(char)) > 0)
    {
        if(c != '\0')
            len++;
    }
    return (len);
}

char *get_file_data(char *src)
{
    int file;
    char c;
    char *file_data;
    int i;

    file_data = (char*)malloc(get_file_data_len(src) * sizeof(char));
    if(!file_data)
        return (0);

    file = open(src, O_RDONLY);
    if (file == -1)
        return (0);
    i = -1;
    while (read(file , &c, sizeof(char)) > 0)
    {
        if(c != '\0')
            file_data[++i] = c;
    }
    return (file_data);
}

int read_file(char *src)
{
    int i;
    char *file_data;
    char **table;

    file_data = get_file_data(src);
    if(!file_data)
        return (0);
    table = generate_table(file_data, get_data_x_y(file_data, 'x'), get_data_x_y(file_data, 'y'));
    if(!table)
        return (0);

    i = -1;
    if(!optimation(table,get_data_x_y(file_data, 'x') * get_data_x_y(file_data, 'y')))
        return (0);
    free(file_data);
    while (table[++i])
        free(table[i]);
    free(table);
    return (1);
}