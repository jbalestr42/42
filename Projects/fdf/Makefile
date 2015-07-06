# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 09:27:42 by jbalestr          #+#    #+#              #
#    Updated: 2013/12/18 15:16:59 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LMLX = -L/usr/X11/lib -lmlx -lXext -lX11
FLAGS = -g -Wall -Werror -Wextra
IDIR = includes/
SDIR = src/
OBJDIR = obj/
SRC = $(SDIR)ft_draw.c $(SDIR)ft_isdigit.c $(SDIR)ft_intsplit.c \
	  $(SDIR)main.c $(SDIR)ft_strsub.c $(SDIR)ft_events.c $(SDIR)ft_atoi.c \
	  $(SDIR)get_next_line.c $(SDIR)ft_compute.c $(SDIR)ft_init.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@gcc $(FLAGS) $(LMLX) -o $@ $^ -I $(IDIR)

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
	./$(NAME) 43

.PHONY: all $(NAME) clean fclean re
