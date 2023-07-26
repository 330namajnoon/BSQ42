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

int check_base(char *base)
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
    return (1);
}