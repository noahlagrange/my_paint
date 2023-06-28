##
## EPITECH PROJECT, 2022
## my_hunter
## File description:
## my_hunter
##

NAME = my_paint

CC = gcc

SRC = 	main.c			\
		create_win.c	\
		create_back.c	\
		create_buttons.c	\
		draw_but.c	\
		buttons_fonc.c	\
		create_bar.c	\
		make_paint.c	\
		link_pos.c	\
		drawer_pix.c	\
		color.c		\
		initialization.c	\
		clicked.c	\
		broche.c	\
		nav_menu.c	\
		size.c		\
		create_size.c	\
		nav_set.c	\
		rond.c		\
		create_typef.c	\
		if_click.c	\
		draw_help_about.c	\
		files_actions.c	\


CFLAGS = -W -Werror -Wall -Wextra -g -g3

LFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

INCLUDE = -I include/

RM = rm -rf

all:
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LFLAGS) $(INCLUDE)

clean:
	$(RM) src/*.o
	$(RM) ./*.o

fclean: clean
	$(RM) $(NAME)

re: clean all
