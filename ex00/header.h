#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h> 

struct Pos {
    int x;
    int y;
    int w;
    int h;
};

struct Size
{
    int x;
    int y;
};


int bsq(int arg_number, char **src);
int read_file(char *src);
int optimation(char **table, struct Size size,char *base);
char *get_base(char *file_data,char *base,int data_file_len);
int my_getchar();
int check_base(char *base);

#endif