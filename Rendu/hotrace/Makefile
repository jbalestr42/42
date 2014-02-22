# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 09:27:42 by jbalestr          #+#    #+#              #
#    Updated: 2013/12/15 16:27:11 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace
FLAGS = -Wall -Werror -Wextra -O3
INCLUDEDIR = includes/
SRCDIR = src/
OBJDIR = obj/
HELPERS = $(SRCDIR)ft_strdup.c $(SRCDIR)ft_strdel.c $(SRCDIR)ft_strlen.c \
		  $(SRCDIR)ft_putstr.c $(SRCDIR)ft_putendl.c $(SRCDIR)ft_avladd.c \
		  $(SRCDIR)ft_avldel.c $(SRCDIR)ft_avlheight.c $(SRCDIR)ft_strcmp.c \
		  $(SRCDIR)ft_avlsearch.c $(SRCDIR)error.c $(SRCDIR)hash5.c \
		  $(SRCDIR)ft_avlnew.c
SRC = $(SRCDIR)main.c $(SRCDIR)get_next_line.c $(HELPERS)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@gcc $(FLAGS) -o $@ $^ -I $(INCLUDEDIR)

%.o:%.c
	@echo "-> Compiling $<..."
	@gcc $(FLAGS) -c -o $@ $< -I $(INCLUDEDIR)

clean:
	@echo "-> Cleaning object files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
