##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##


NAME = my_sokoban

SRC = 	src/main.c				\
		src/check_error.c		\
		src/game.c				\
		src/move_player.c		\
		src/move_with_box.c		\
		src/count_box.c			\
		src/check_zero.c		\
		src/move_player2.c		\
		src/check_o.c			\
		src/get_map.c			\
		src/check_win_lose.c

CFLAGS = -W -Wall -Wextra -I ./include

OBJ = $(SRC:%.c=%.o)

LIB = -L ./lib/my -lmy

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB) -lncurses

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my

re:	fclean all
