##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## It's the Makefile
##

LIB	=	lib/my_strlen.c      \
		lib/my_atoi.c	\
		lib/my_putchar.c     \
		lib/my_put_nbr.c     \
		lib/my_putstr.c      \
		lib/my_strcmp.c      \
		lib/my_strncat.c     \
		lib/my_strncpy.c     \
		lib/my_printf.c	\
		lib/my_itoa.c	\
		lib/str_to_array.c	\
		lib/my_tab.c 	\

TESTS = $(shell find tests -name "*.c" -type f)

SRC =	$(shell find src -name "*.c" -type f)

OBJ = $(LIB:.c=.o)

NAME = my_sokoban

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CRITERION = -lcriterion --coverage

ERROR = -Werror -Wall -pedantic -g3

all: $(NAME)

lib: $(OBJ)
	@ar rc libmy.a $(OBJ)
	@rm -f $(OBJ)
	@echo ">>> Library compiled."

$(NAME): lib
	@gcc $(ERROR) -lncurses -o ${NAME} $(SRC) -L. libmy.a
	@rm -f libmy.a
	@echo ">>> Executable \"${NAME}\" created."

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f bonus
	@echo ">>> All files was clean."

re: fclean all

unit_tests: fclean lib
	@gcc $(ERROR) -o unit_tests $(SRC) $(TESTS) $(CRITERION) -L. libmy.a
	./unit_tests
	@rm -f libmy.a
	@rm -f *.gcno *.gcda
	@rm -f unit_tests
