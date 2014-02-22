# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/02 17:52:14 by pciavald          #+#    #+#              #
#    Updated: 2014/01/10 14:10:20 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SDIR = ./src/
IDIR = ./includes/
LIBFT = -I./libft/includes -L./libft
LIBTERM = -L/usr/lib
LIBS = -lft -ltermcap
SRC = $(SDIR)main.c $(SDIR)helpers.c $(SDIR)term.c $(SDIR)select.c
OBJ = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	@make -C libft

libclean:
	@make fclean -C libft

$(NAME): $(OBJ)
	@echo " - Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -I$(IDIR) $^ -o $(NAME) $(LIBTERM) $(LIBFT) $(LIBS)
	@echo "Done."

%.o:%.c
	@echo " - Creating $<..."
	@$(CC) $(CFLAGS) -I$(IDIR) $(LIBFT) $(LIBTERM) -c $< -o $@

clean:
	@echo " - Cleaning object files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo " - Cleaning binary..."
	@/bin/rm -f $(NAME)

libre: libclean fclean all

re: fclean all

.PHONY : clean fclean re
