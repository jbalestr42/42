# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 11:57:09 by jbalestr          #+#    #+#              #
#    Updated: 2014/02/08 12:46:02 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
SDIR = sources/
ODIR = objects/
IDIR = -I includes/ -I gnl/includes/
LIB = -L gnl/ -lftgnl
SRC = main.c helpers.c
:wq
OBJ = $(SRC:.c=.o)
EXT = includes/client.h
S = $(addprefix $(SDIR), $(SRC))
O = $(addprefix $(ODIR), $(OBJ))

all: lib $(NAME)

$(NAME): $(O) $(EXT)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) $^ -o $(NAME) $(IDIR) $(LIB)

$(ODIR)%.o: $(SDIR)%.c
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) $(IDIR) -c $< -o $@

$(O): | ./objects

./objects:
	@mkdir $(ODIR)

lib:
	@make -C gnl

clean:
	@echo "-> Cleaning .o files..."
	@/bin/rm -rf $(ODIR)
	@make clean -C gnl

fclean: clean
	@echo "-> Removing binary..."
	@/bin/rm -f $(NAME)
	@make fclean -C gnl

re: fclean all

.PHONY: all clean fclean re
