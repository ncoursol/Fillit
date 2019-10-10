# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 19:03:50 by ncoursol          #+#    #+#              #
#    Updated: 2019/05/09 14:16:51 by dberger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
COMP_COLOR = \033[33m
BIN_COLOR = \033[32m
BIN2_COLOR = \033[36m
PROG_COLOR = \033[35m

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft

SOURCES = fillit.c\
ft_backtrack.c\
ft_check.c\
ft_map.c\
ft_display.c\
ft_storage.c\

OBJ = $(SOURCES:.c=.o)

INCLUDE = fillit.h

.PHONY: all clean fclean re norme

$(NAME): $(OBJ)
	@(cd $(LIB_DIR) && $(MAKE))
	@$(CC) $(FLAGS) -o $(NAME) $(SOURCES) $(LIB_DIR)/libft.a
	@echo "$(COMP_COLOR)   --- Compiled ! ---  $(NO_COLOR)"

all: $(NAME)

norme:
	@norminette $(SRC)

clean:
	@rm -rf $(OBJ)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@echo "$(BIN2_COLOR)   --- Binary   deleted ---        $(NO_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@echo "$(PROG_COLOR)   --- Program  deleted ---        $(NO_COLOR)"

re: fclean all
