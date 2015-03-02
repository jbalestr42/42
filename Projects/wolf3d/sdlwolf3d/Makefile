# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 09:27:42 by jbalestr          #+#    #+#              #
#    Updated: 2014/01/02 19:55:40 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LMLX = -lSDLmain -lSDL
FLAGS = -Wall -Werror -Wextra
IDIR = includes/
SDIR = sources/
SRC = $(SDIR)main.c $(SDIR)events.c $(SDIR)draw.c $(SDIR)init.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@gcc $(FLAGS) -o $@ $^ -I $(IDIR) $(LMLX)

%.o:%.c
	@echo "-> Compiling $<..."
	@gcc $(FLAGS) -c -o $@ $< -I $(IDIR) $(LMLX)

clean:
	@echo "-> Cleaning object files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all

run: re

.PHONY: all $(NAME) clean fclean re
