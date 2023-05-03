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

#Library directories
ARM=lib/arm/libftprintf.a \
	lib/arm/libft.a
AMD=lib/amd/libftprintf.a \
	lib/amd/libft.a

#ShellCommands
UNAME_P=$(shell uname -p)
FIND_OBJ_FOLDER=$(shell find src/ -type d -name "obj")

#Source files
SRC=src/main.c
OBJ=$(SRC:%.c=%.o)

#Phony targets
.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
	@make -C lib/ft_printf/
	@make -C lib/libft/
	$(CC) $(CFLAGS) $(SRC) lib/ft_printf/libftprintf.a lib/libft/libft.a -o $(NAME)
	@echo "$(COLOUR_GREEN)Compiled$(COLOUR_END)"

sanitize:
	$(CC) $(SRC) lib/libftprintf.a lib/libft.a -fsanitize=address -g -o $(NAME)
	@echo "$(COLOUR_GREEN)Make Sanitize Done$(COLOUR_END)"

clean:
	$(RM) $(OBJ)
	@echo "$(COLOUR_GREEN)$(OBJ) Removed$(COLOUR_END)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) removed$(COLOUR_END)"

run:
	make sanita && ./$(NAME) infile "grep ola" "wc -l" outfile
make re: fclean all