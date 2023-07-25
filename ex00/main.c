#include "header.h"

int main(int argc, char **argv)
{
    if (argc > 1)
        bsq(argc, argv);
    else
        write(1, "Error!", 6);
    return (0);
}