#include "header.h"

int get_base_num(char *base)
{
     char base_c[11];
     int i;

     i = -1;
     while (base[(++i) + 3] != 0)
     {
          base_c[i] = base[i];
     }
     base_c[i+1] = 0;
     return (ft_atoi(base_c)+1);
}

int ft_write(char *src)
{
     struct Vars vars;
     char c;
     int file;
     int line;
     char base[15];
     

     line = 0;
     vars.i = -1;
     vars.j = 1;
     file = open(src, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
     while (++vars.i < 15)
          base[vars.i] = 0;
     vars.i = -1;
     if (file == -1)
          exit(EXIT_FAILURE);
     while ((c = my_getchar()) != EOF && line < vars.j) 
     {
          if (c == '\n' && line == 0)
          {
               base[vars.i + 1] = 0;
               line++;
               vars.j = get_base_num(base);
          }else if (c == '\n' && line > 0)
               line++;
          if(line == 0)
               base[++vars.i] = c;
          if (write(file, &c, sizeof(char)) == -1)
          {
               close(file);
               exit(EXIT_FAILURE);
          }
     }
     return (1);
}

int bsq(int arg_number, char **src)
{
    int i;
    int err;

    if (arg_number == 1)
    {
          ft_write("map");
          err = read_file("map");
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