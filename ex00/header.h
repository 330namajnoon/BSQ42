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

int bsq(int arg_number, char **src);
int read_file(char *src);
int optimation(char **table, int x, int y);
int get_base(char *file_data,char *base);


#endif