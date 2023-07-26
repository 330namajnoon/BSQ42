#include "header.h"

int my_getchar()
{
    char c;
    int bytesRead;

    int fd = open("/dev/stdin", O_RDONLY);

    if (fd == -1) {
        perror("Error al abrir el descriptor de archivo");
        exit(EXIT_FAILURE);
    }
    bytesRead = read(fd, &c, 1);
    close(fd);
    if (bytesRead == 0) {
        return EOF;
    }
    return c;
}

char *get_base(char *file_data, char *base, int data_file_len)
{
    int i;
    int j;
    int k;
    int len;
    char *d;

    i = 0;
    j = -1;
    k = -1;
    len = 1;
    if(!check_table(file_data))
    {
        free(file_data);
        return (0);
    }
    if(file_data[0] == '0' || file_data[0] == '-')
        return (0);

    i = -1;
    while (file_data[++i] != '\n')
        if(file_data[i+3] == '\n' || file_data[i+2] == '\n' || file_data[i+1] == '\n')
            base[++k] = file_data[i];
    base[k+1] = '\0';
    d = (char *)malloc(data_file_len - i);
    i++;
    if (!d)
        return (0);
    while (file_data[i])
    {
        d[++j] = file_data[i];
        i++;
    }
    d[j] = '\0';
    free (file_data);
    return (d);
}

int check_table(char *file_data)
{
    int t;
    char base_n[11];
    char base[11];
    struct Vars vars;
    (void)base;
    vars.i = -1;
    
    t = 0;
    if(file_data[0] == 0 || file_data[0] == '\n')
        return (0);
    while (file_data[(++vars.i) + 3] != '\n' )
    {
        if(!(file_data[vars.i] >= '0' && file_data[vars.i] <= '9'))
            return (0);
        base_n[vars.i] = file_data[vars.i];
    }
    vars.i = 0;
    while (file_data[vars.i] != '\n')
        vars.i++;
    if(vars.i < 3)
        return (0);
    base_n[vars.i+1] = 0;
    vars.i = -1;
    vars.j = 0;
    vars.k = 0;
    while (file_data[++vars.i] != '\0')
    {
        if(file_data[vars.i] == '\n')
        {
            if(vars.j > 0 && t == 0)
                t = vars.k;
            else if(t > 0 && t != vars.k)
                return (0);
            vars.j++;
            vars.k = 0;
        }
        vars.k++;
    }
    if (ft_atoi(base_n) != vars.j - 1)
        return (0);
    return 1;
}


int check_base(char *base, char *file_data)
{
    int i;
    int j;
    int t;

    i = 0;
    while (base[++i] != 0)
    {
        t = 0;
        j = -1;
        while (base[++j] != 0)
        {
            if(base[i] == base[j])
                t++;
            if (t > 1)
                return (0);
        }
    }
    i = -1;
    while (file_data[++i] != 0)
    {
        if(file_data[i] != base[0] && file_data[i] != base[1] && file_data[i] != base[2] && file_data[i] != '\n')
            return (0);
    }
    
    return (1);
}

