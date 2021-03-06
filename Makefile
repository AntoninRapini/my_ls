##
## Makefile for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Tue Nov 29 08:50:17 2016 Antonin Rapini
## Last update Fri Dec  2 20:39:20 2016 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS 	+= -I include

SRC	=	src/sorting/my_atimecmp.c	\
		src/sorting/my_mtimecmp.c	\
		src/sorting/my_namecmp.c	\
		src/sorting/my_nocmp.c		\
		src/sorting/my_sort_list.c	\
		src/sorting/my_reverse_list.c	\
		src/display/my_display_default.c	\
		src/display/my_display_line.c	\
		src/display/my_display.c	\
		src/display/my_display_recursive.c	\
		src/display/my_get_typespecifier.c	\
		src/my_set_options.c	\
		src/my_create_list.c	\
		src/my_create_fileinfos.c	\
		src/display/my_format_line.c	\
		utils/my_strdup.c	\
		utils/my_strlen.c	\
		utils/my_putstr.c	\
		utils/my_nstrcat.c	\
		utils/my_put_nbr.c	\
		utils/my_putchar.c	\
		utils/my_int_tostr.c	\
		utils/my_showblocks.c	\
		my_ls.c

OBJ	=	$(SRC:.c=.o)

NAME	= 	my_ls

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
