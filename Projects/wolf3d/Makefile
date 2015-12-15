# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 09:27:42 by jbalestr          #+#    #+#              #
#    Updated: 2015/07/09 15:16:14 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LMLX = -L/usr/local/lib/ -lmlx -lm -framework OpenGL -framework AppKit
FLAGS = -g -Wall -Werror -Wextra
IDIR = includes/
SDIR = sources/
SRC = $(SDIR)main.c $(SDIR)events.c $(SDIR)draw.c $(SDIR)init.c $(SDIR)math.c \
	  $(SDIR)compute.c $(SDIR)init_events.c $(SDIR)key_events_move.c \
	  $(SDIR)key_events_spec.c $(SDIR)init_image.c $(SDIR)intsplit.c \
	  $(SDIR)init_map.c $(SDIR)get_next_line.c $(SDIR)key_events_look.c \
	  $(SDIR)trigger.c $(SDIR)helper.c $(SDIR)hud.c $(SDIR)key_event_hud.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@gcc $(FLAGS) -o $@ $^ -I $(IDIR) -I /usr/local/include/ $(LMLX)

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
