##
## EPITECH PROJECT, 2024
## B-CPE-110-LYN-1-1-organized-pierre.baud
## File description:
## Makefile
##

SRC     =       main.c \
                add_f.c \
                annexe.c \
				sort_f.c \
				del_f.c \
				disp_f.c \

OBJ     =       $(SRC:.c=.o)

LIB     =       -Lsrc -lshell

NAME    =       organized

all:    $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LIB)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
