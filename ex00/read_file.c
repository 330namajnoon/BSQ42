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
        data[i] = (char*)malloc((x + 1) * sizeof(char));
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
            data[j][k+1] = 0;
            j++;
            k = -1;
        }else
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
    
    file = open(src, O_RDONLY);
    if (file == -1)
        return (0);
    file_data = (char*)malloc((get_file_data_len(src) + 1) * sizeof(char));
    if(!file_data)
        return (0);

    i = -1;
    while (read(file , &c, sizeof(char)) > 0)
    {
        if(c != '\0')
            file_data[++i] = c;
    }
    file_data[i+1] = '\0';
    close(file);
    return (file_data);
}

int read_file(char *src)
{
    int i;
    char *file_data;
    char **table;
    char base[4];
    struct Size size;
    
    if(open(src,O_RDONLY) == -1)
        return (1);
    file_data = get_base(get_file_data(src), base, get_file_data_len(src));
    if(!file_data)
        return (1);
    if(!check_base(base))
        return (2);
    table = generate_table(file_data, get_data_x_y(file_data, 'x'), get_data_x_y(file_data, 'y'));
    if(!table)
        return (2);
    size.x = get_data_x_y(file_data, 'x');
    size.y = get_data_x_y(file_data, 'y');
    if(!optimation(table,size,base))
        return (2);
    i = -1;
    while (++i < get_data_x_y(file_data, 'y'))
        free(table[i]);
    free(table);
    free(file_data);
    return (0);
}