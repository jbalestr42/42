# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 13:21:56 by pciavald          #+#    #+#              #
#    Updated: 2013/12/15 13:26:30 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Werror -Wextra
INC = includes
SRCDIR = srcs/
SRC = $(SRCDIR)ft_ls.c $(SRCDIR)ft_init_helper.c $(SRCDIR)main.c \
	  $(SRCDIR)ft_display.c $(SRCDIR)ft_error.c $(SRCDIR)ft_avl_helper.c \
	  $(SRCDIR)ft_small_helpers.c $(SRCDIR)ft_print_helper.c \
	  $(SRCDIR)ft_max_size.c
OBJ = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -I libft/includes -L libft/ -lft

%.o:%.c
	@echo "-> Compiling $<..."
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I libft/includes

lib:
	@echo "-> Compiling libft..."
	@make -C libft

clean:
	@echo "-> Cleaning object files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) all lib clean fclean re
