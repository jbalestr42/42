# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 11:57:09 by jbalestr          #+#    #+#              #
#    Updated: 2014/01/24 16:56:40 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell2
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
LIBFT = -L./libft -lft
SDIR = sources/
ODIR = objects/
IDIR = -I includes/ -I libft/includes/
SRC = main.c error.c get_next_line.c prompt.c helpers.c lexer.c list.c cd.c \
	  env.c getenv.c setenv.c unsetenv.c exit.c builtin.c init_lex.c \
	  check_rules.c define_type.c
OBJ = $(SRC:.c=.o)
EXT = includes/gnl.h includes/ft_minishell1.h includes/ft_minishell2.h
S = $(addprefix $(SDIR), $(SRC))
O = $(addprefix $(ODIR), $(OBJ))

all: lib $(NAME)

$(NAME): $(O) $(EXT)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) $(IDIR) $^ -o $(NAME) $(LIBFT)

$(ODIR)%.o: $(SDIR)%.c
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) $(IDIR) -c $< -o $@

lib:
	@make -C libft

$(O): | ./objects

./objects:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning .o files..."
	@/bin/rm -rf $(ODIR)
	@make clean -C libft

fclean: clean
	@echo "-> Removing binary..."
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
