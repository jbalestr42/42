# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 11:57:09 by jbalestr          #+#    #+#              #
#    Updated: 2014/02/08 12:45:39 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
SDIR = sources/
ODIR = objects/
IDIR = -I includes/ -I printf/includes
LIB = -L ./printf/ -lftp
SRC = main.c helpers.c get_signal.c list.c
OBJ = $(SRC:.c=.o)
EXT = includes/server.h printf/includes/ft_printf.h
S = $(addprefix $(SDIR), $(SRC))
O = $(addprefix $(ODIR), $(OBJ))

all: lib $(NAME)

$(NAME): $(O) $(EXT)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) $^ -o $(NAME) $(IDIR) $(LIB)

$(ODIR)%.o: $(SDIR)%.c
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) $(IDIR) -c $< -o $@

lib:
	@echo "-> Compiling printf..."
	@make -C printf

$(O): | ./objects

./objects:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning .o files..."
	@/bin/rm -rf $(ODIR)
	@make clean -C printf

fclean: clean
	@echo "-> Removing binary..."
	@/bin/rm -f $(NAME)
	@make fclean -C printf

re: fclean all

.PHONY: all clean fclean re
