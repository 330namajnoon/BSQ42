program: main.c bsq.c read_file.c optimation.c utils.c
	gcc -Wall -Wextra -Werror main.c bsq.c read_file.c optimation.c utils.c -o bsq
program_m: main.c bsq.c read_file.c optimation.c utils.c
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 main.c bsq.c read_file.c optimation.c utils.c -o bsq
fclear: rm bsq