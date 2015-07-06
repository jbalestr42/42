# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 11:57:09 by jbalestr          #+#    #+#              #
#    Updated: 2014/01/24 16:56:40 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftp.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SDIR = sources/
ODIR = objects/
IDIR = includes/
SRC = ft_strlen.c ft_parser.c ft_putstr.c ft_printf.c ft_putchar.c ft_putnbr.c \
	  ft_putoctal.c ft_puthexa.c ft_helper.c ft_isdigit.c ft_putaddr.c \
	  ft_putbin.c ft_intlen.c ft_valid_opt.c ft_putfnbr.c ft_putnbropt.c
OBJ = $(SRC:.c=.o)
EXT = ft_printf.h
S = $(addprefix $(SDIR), $(SRC))
O = $(addprefix $(ODIR), $(OBJ))
E = $(addprefix $(IDIR), $(EXT))

all: $(NAME)

$(NAME): $(O) $(E)
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
