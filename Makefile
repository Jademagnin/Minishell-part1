##
## EPITECH PROJECT, 2023
## navy
## File description:
## Makefile
##

NAME = mysh
CC	= gcc
SRC	= src/main.c \
	src/minishell.c \
	src/helpers/execution.c \
	src/helpers/errors.c \
	src/helpers/display.c \
	src/helpers/path.c \
	src/helpers/utils.c \
	src/functions/cd.c \
	src/functions/exit.c \
	src/functions/env.c \
	src/functions/setenv.c \
	src/functions/unsetenv.c \

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -Wall -Wextra -L lib/my -lmy -I ./include -I ../lib/my/include \
		-D _DEFAULT_SOURCE

all: $(NAME)
$(NAME):
	make -C lib/my/
	cp lib/my/include/my.h include
	$(CC) -o $(NAME) $(SRC) $(LIBFLAG) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

tests_run:
	make re
	clear
	./tests/tester.sh

re: fclean all

cstyle:
	make fclean
	cstyle
