#include "header.h"

int chek_square(char **table, struct Pos *pos, struct Size size,char *base)
{
    int x;
    int y;

    y = -1;
    if(pos->w > size.x-1 || pos->h > size.y-1)
        return (0);
    while (++y < size.y)
    {
        x = -1;
        while (++x < size.x)
            if(x >= pos->x && x <= pos->w && y >= pos->y && y <= pos->h)
                if(table[y][x] == base[1] || table[y][pos->w] == '\0' || !table[pos->h])
                    return (0);
    }
    return (1);
}

void print_square(char **table,struct Pos pos,struct Size size, char *base)
{
    int x;
    int y;

    y = -1;
    while (++y < size.y)
    {
        x = -1;
        while (++x < size.x){
            if(x >= pos.x && x <= pos.w && y >= pos.y && y <= pos.h)
                table[y][x] = base[2];
            write(1,&table[y][x],1);
        }
        write(1,"\n",1);
    }
}

void get_max_square(char **table,struct Pos *poss, struct Size size,char *base)
{
    int i;
    int max_i;
    int *max_p;
    int max;
    (void)table;
    i = -1;
    max_i = -1;
    max_p = (int *)malloc((size.x * size.y) * sizeof(int));
    max = 0;
    while (++i < (size.x * size.y))
        if(poss[i].w - poss[i].x > poss[max].w - poss[max].x)
            max = i;
    i = -1;
    while (++i < (size.x * size.y))
        if(poss[i].w - poss[i].x == poss[max].w - poss[max].x)
            max_p[++max_i] = i;
    i = -1;
    max = max_p[0];
    while (++i < (size.x * size.y))
        if(max_p[i] >= 0)
            if(poss[max_p[i]].x < poss[max].x || poss[max_p[i]].y < poss[max].y)
                max = max_p[i];
    
    print_square(table,poss[max_p[0]],size,base);
    free(max_p);
}

int optimation(char **table, struct Size size,char *base)
{
    int i;
    struct Pos pos;
    struct Pos *poss;
    pos.x = 0;
    pos.y = 0;
    pos.w = pos.x;
    pos.h = pos.y;

    poss = (struct Pos*)malloc((size.x * size.y) * sizeof(struct Pos));
    i = -1;
    while (pos.y < size.y)
    {
        pos.x = -1;
        while (++pos.x < size.x)
        {
            pos.w = pos.x;
            pos.h = pos.y;
            while (chek_square(table, &pos,size,base))
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
    get_max_square(table,poss,size,base);
    free(poss);
    return (1);
}