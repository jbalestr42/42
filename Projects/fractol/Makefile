# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 09:27:42 by jbalestr          #+#    #+#              #
#    Updated: 2015/03/04 17:40:58 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LMLX = -L/usr/local/lib/ -lmlx -lm -framework OpenGL -framework AppKit
FLAGS = -Wall -Werror -Wextra -o3
IDIR = includes/
SDIR = sources/
SRC = $(SDIR)main.c $(SDIR)events.c $(SDIR)init.c $(SDIR)draw.c $(SDIR)fractal.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@gcc $(FLAGS) -o $@ $^ $(LMLX)

%.o:%.c
	@echo "-> Compiling $<..."
	@gcc $(FLAGS) -c -o $@ $< -I $(IDIR) -I /usr/local/include/

clean:
	@echo "-> Cleaning object files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all

run: re

.PHONY: clean fclean re
