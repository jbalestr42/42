# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 11:44:44 by jbalestr          #+#    #+#              #
#    Updated: 2014/01/22 15:27:28 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
FLAGS = -g -Wall -Werror -Wextra
SDIR = sources/
IDIR = includes/
SRC = $(SDIR)main.c $(SDIR)get_next_line.c $(SDIR)filler.c $(SDIR)read.c \
	  $(SDIR)init.c $(SDIR)read.c $(SDIR)ft_strsplit.c $(SDIR)ft_atoi.c \
	  $(SDIR)ft_strdup.c $(SDIR)ft_strlen.c $(SDIR)ft_strdel.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@gcc $(FLAGS) -o $@ $^ -I $(IDIR)

%.o: %.c
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
	./vm/ruby-2.1.0/bin/ruby vm/vm_beta.rb -f map -p1 ./filler -p2 vm/./superjeannot.filler

.PHONY: clean fclean re
