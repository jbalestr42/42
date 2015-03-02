# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 09:27:42 by jbalestr          #+#    #+#              #
#    Updated: 2013/12/29 15:09:37 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -g -Wall -Werror -Wextra
IDIR = includes/
SDIR = src/
OBJDIR = obj/
SRC = $(SDIR)swap_lst.c $(SDIR)rotate_lst.c $(SDIR)init_lst.c \
	  $(SDIR)ft_atoi.c $(SDIR)main.c $(SDIR)rrotate_lst.c \
	  $(SDIR)pswap_lst.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@gcc $(FLAGS) -o $@ $^ -I $(IDIR)

%.o:%.c
	@echo "-> Compiling $<..."
	@gcc $(FLAGS) -c -o $@ $< -I $(IDIR)

clean:
	@echo "-> Cleaning object files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) 12 15 10 18 6 11

.PHONY: clean fclean re
