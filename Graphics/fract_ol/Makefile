# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 09:27:42 by jbalestr          #+#    #+#              #
#    Updated: 2015/03/20 21:50:12 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LMLX = -L/usr/local/lib/ -lmlx -lm -lXext -lX11
FLAGS = -Wall -Werror -Wextra -Ofast
IDIR = includes/
SDIR = sources/
SRC = $(SDIR)main.c $(SDIR)events.c $(SDIR)init.c $(SDIR)draw.c \
	  $(SDIR)fractal.c $(SDIR)init_images.c $(SDIR)mandelbrot.c \
	  $(SDIR)key.c $(SDIR)julia.c
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
