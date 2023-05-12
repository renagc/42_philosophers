#Colors
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#Targets
NAME = philo

#Compiler flags
CC = @gcc
CFLAGS = -Wall -Wextra -Werror -pthread

RM = @rm -rf

#lib
LIBFT_A=lib/libft/libft.a

#ShellCommands
FIND_OBJ_FOLDER=$(shell find src/ -type d -name "obj")

#Source files
SRC=src/main.c src/lst_philos.c
OBJ=$(SRC:%.c=%.o)

#Phony targets
.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
	@make -C lib/libft/
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_A) -o $(NAME)
	@echo "$(COLOUR_GREEN)Program Compiled: Success$(COLOUR_END)"

sanitize:
	$(CC) $(SRC) $(LIBFT_A) -fsanitize=address -g -o $(NAME)
	@echo "$(COLOUR_GREEN)Make Sanitize Done$(COLOUR_END)"
	make run

valgrind: all
	valgrind  ./$(NAME)

clean:
	@make clean -C lib/libft/
	$(RM) $(OBJ)
	@echo "$(COLOUR_GREEN)$(OBJ) Removed$(COLOUR_END)"

fclean: clean
	@make fclean -C lib/libft/
	$(RM) $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) removed$(COLOUR_END)"

run: all
	@echo "\nExecuting Program:\n"
	./$(NAME) 5 200 200 10

re: fclean all