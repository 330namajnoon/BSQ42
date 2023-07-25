#include "header.h"

int chek_square(char **table, struct Pos *pos, char *base)
{
    int x;
    int y;

    y = -1;

    while (table[++y])
    {
        x = -1;
        while (table[y][++x] != '\0')
            if(x >= pos->x && x <= pos->w && y >= pos->y && y <= pos->h)
                if(table[y][x] == base[1] || table[y][pos->w] == '\0' || !table[pos->h])
                    return (0);
    }
    return (1);
}

void print_square(char **table,struct Pos pos, char *base)
{
    int x;
    int y;

    y = -1;

    while (table[++y])
    {
        x = -1;
        while (table[y][++x] != '\0'){
            if(x >= pos.x && x <= pos.w && y >= pos.y && y <= pos.h)
                table[y][x] = base[2];
            write(1,&table[y][x],1);
        }
        write(1,"\n",1);
    }
}

void get_max_square(char **table,struct Pos *poss, int total, char *base)
{
    int i;
    int max_i;
    int *max_p;
    int max;

    i = -1;
    max_i = -1;
    max_p = (int *)malloc(total * sizeof(int));
    max = 0;
    while (++i < total)
        if(poss[i].w - poss[i].x > poss[max].w - poss[max].x)
            max = i;
    i = -1;
    while (++i < total)
        if(poss[i].w - poss[i].x == poss[max].w - poss[max].x)
            max_p[++max_i] = i;
    i = -1;
    max = max_p[0];
    while (max_p[++i])
        if(poss[max_p[i]].x < poss[max].x || poss[max_p[i]].y < poss[max].y)
            max = max_p[i];
    print_square(table,poss[max_p[0]],base);
    free(max_p);
}

int optimation(char **table, int total,char *base)
{
    int i;
    struct Pos pos;
    struct Pos *poss;
    pos.x = 0;
    pos.y = 0;
    pos.w = pos.x;
    pos.h = pos.y;

    poss = (struct Pos*)malloc(total * sizeof(struct Pos));
    i = -1;
    while (table[pos.y])
    {
        pos.x = -1;
        while (table[pos.y][++pos.x] != '\0')
        {
            pos.w = pos.x;
            pos.h = pos.y;
            while (chek_square(table, &pos, base))
            {
                pos.w++;
                pos.h++;
            } 
            poss[++i].x = pos.x;
            poss[i].y = pos.y;
            poss[i].w = pos.w - 1;
            poss[i].h = pos.h - 1;
        }
        pos.y++;
    } 
    get_max_square(table,poss,total, base);
    free(poss);
    return (1);
}