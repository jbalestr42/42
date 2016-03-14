# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 11:57:09 by jbalestr          #+#    #+#              #
#    Updated: 2016/03/11 11:00:41 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftgnl.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SDIR = sources/
ODIR = objects/
IDIR = includes/
SRC = get_next_line.c ft_bzero.c ft_strchr.c
OBJ = $(SRC:.c=.o)
EXT = $(IDIR)gnl.h
S = $(addprefix $(SDIR), $(SRC))
O = $(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O) $(EXT)
	@echo "-> Creating $(NAME)..."
	@ar rc $(NAME) $(O)
	@echo "-> Optimising $(NAME)..."
	@ranlib $(NAME)
	@echo "-> Done !"

$(ODIR)%.o: $(SDIR)%.c
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -I$(IDIR) -c $< -o $@

$(O): | ./objects

./objects:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning object files..."
	@/bin/rm -rf $(ODIR)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
