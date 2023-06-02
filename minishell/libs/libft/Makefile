# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martiper <martiper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 15:25:36 by martiper          #+#    #+#              #
#    Updated: 2023/05/28 23:16:02 by martiper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME = Libft

SRCS_DIR = src

SRCS =	ft_atoi.c \
		ft_atol.c \
		ft_is_ascii.c \
		ft_isdigit.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_strcpy.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_ltoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_str_startswith.c \
		ft_strrep.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstfind.c \
		ft_lstremove.c \
		ft_lstsort.c \
		printf/ft_printf_putaddress.c \
		printf/ft_printf_putchar.c \
		printf/ft_printf_putnbrs.c \
		printf/ft_printf_putstr.c \
		printf/ft_printf_putfloat.c \
		printf/ft_printf.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		sprintf/ft_sprintf_putaddress.c \
		sprintf/ft_sprintf_putchar.c \
		sprintf/ft_sprintf_putnbrs.c \
		sprintf/ft_sprintf_putstr.c \
		sprintf/ft_sprintf_putfloat.c \
		sprintf/ft_sprintf.c

OBJ_DIR = objs

SRC_FILES = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

ARCH_DIR = bin
NAME =	$(addprefix $(ARCH_DIR)/, libft.a)

### COLORS ###

RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[93m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[96m
RESET = \033[0m

TAG = [$(CYAN)$(PROJECT_NAME)$(RESET)]

### END OF COLORS ###

all: $(NAME)

$(NAME) : $(OBJS)
	@mkdir -p $(dir $@)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(TAG) compiled version $(YELLOW)$$(cat VERSION)$(RESET)!"

$(OBJ_DIR)/%.o: %.c
	@echo "$(TAG) building $(YELLOW)$<$(RESET).."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(TAG) cleaned $(YELLOW)objects!$(RESET)\n"
	@rm -rf $(OBJS) $(OBJ_DIR)

fclean: clean
	@printf "$(TAG) cleaned $(YELLOW)archive!$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
