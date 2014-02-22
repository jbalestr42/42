# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/25 17:29:42 by pciavald          #+#    #+#              #
#    Updated: 2013/12/31 00:51:57 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/includes/ -L./libft
SDIR = src/
IDIR = includes/
BDIR = builtin/
BUI = $(BDIR)cd.c $(BDIR)env.c $(BDIR)getenv.c $(BDIR)setenv.c \
	  $(BDIR)unsetenv.c $(BDIR)exit.c $(SDIR)builtin.c
SRC = $(SDIR)main.c $(SDIR)error.c $(SDIR)get_next_line.c $(SDIR)prompt.c \
	  $(SDIR)helpers.c $(BUI)
OBJ = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -I$(IDIR) -I$(LIBFT) $^ -o $(NAME) -lft

%.o:%.c
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -I$(IDIR) -c $< -o $@

lib:
	@echo "Compiling libft..."
	@make -C libft

clean:
	@echo "-> Cleaning .o files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "-> Removing binary..."
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
