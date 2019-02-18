##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/events.c \
		src/main.c \
		src/init_struct.c \
		src/print.c \
		src/move.c \
		src/framerate.c \
		src/destroy.c \
		src/init_window.c \
		src/music.c \
		src/time.c \
		src/options.c \
		src/flags.c \
		src/globals.c \
		src/map.c \
		src/hitbox.c \
		src/map2.c \
		src/init_graphics.c \
		src/menu.c \
		src/level.c \
		src/lose.c \
		src/win.c \
		src/score.c \
		src/text.c

NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)

LIB_PATH	=	./lib/my/

LIB_NAME	=	my

TEST_PATH 	= 	./tests/

CFLAGS	=	-W -Wall -I include/ -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME) clean

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) -L$(LIB_PATH) -l$(LIB_NAME) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB_PATH)libmy.a
	rm -f unit_test*

re:	fclean all

tests_run: