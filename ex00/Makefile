program: main.c bsq.c read_file.c optimation.c utils.c str_libs.c
	gcc -Wall -Wextra -Werror main.c bsq.c read_file.c optimation.c utils.c str_libs.c -o bsq
program_m: main.c bsq.c read_file.c optimation.c utils.c str_libs.c
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 main.c bsq.c read_file.c optimation.c utils.c str_libs.c -o bsq
fclear: rm bsq