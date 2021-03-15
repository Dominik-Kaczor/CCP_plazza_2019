##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for the ex00
##

DIR_SRC		=	src/

DIR_TESTS	=	tests/

SRC		=	$(DIR_SRC)Main/Main.cpp			\
			$(DIR_SRC)Main/Core.cpp			\
			$(DIR_SRC)Thread/Cvariables.cpp		\
			$(DIR_SRC)Thread/Process.cpp		\
			$(DIR_SRC)Thread/Orders.cpp		\
			$(DIR_SRC)Thread/Mutex.cpp		\
			$(DIR_SRC)Thread/Thread.cpp 		\
			$(DIR_SRC)Arguments/Arguments.cpp 	\
			$(DIR_SRC)Plazza/Plazza.cpp

SRC_TESTS	=	tests/test.cpp

OBJ		=	$(SRC:.cpp=.o)

OBJ_TESTS	=	$(SRC_TESTS:.cpp=.o)

CPPFLAGS	=	-I ./src/ -Wall -Wextra

NAME		=	plazza

CC		=	g++ -g -lpthread -pthread

RM		=	rm -f

NAME_TESTS	=	unit_tests

LIB_CRITERION	=	-lcriterion --coverage


%.o: %.cpp
		@$(CC) $(CPPFLAGS) -c $< -o $@
		@printf "[\033[0;32mCompilation\033[0m] % 30s\n" $< | tr ' ' '.'

all:		$(NAME)

$(NAME):	$(OBJ)
		@printf "[\033[0;33mBuild\033[0m] % 32s\n" $(NAME) | tr ' ' '.'
		@$(CC) -o $(NAME) $(OBJ)

tests_run:	fclean $(OBJ_TESTS)
		$(CC) $(CPPFLAG) $(CPPFLAGS) -o $(NAME_TESTS) $(SRC_TESTS) $(LIB_CRITERION)
		$(RM) $(OBJ_TESTS)
		./$(NAME_TESTS)

clean:
		@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'
		@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'
		@$(RM) $(NAME)
		@$(RM) $(OBJ)
		@$(RM) log.txt

tests_clean:
		@printf "[\033[0;31mDeleted\033[0m] % 30s\n" $(NAME_TESTS) | tr ' ' '.'
		@$(RM) $(NAME_TESTS)
		@$(RM) *.gcda
		@$(RM) *.gcno

fclean:		clean tests_clean

re:		fclean all

debug:		CFLAGS	+=	-g3
debug:		re

.PHONY:		tests_run tests_clean fclean re
