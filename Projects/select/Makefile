# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/30 14:08:31 by jbalestr          #+#    #+#              #
#    Updated: 2014/04/30 14:08:33 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SDIR = ./src/
IDIR = ./includes/
LIBTERM = -L/usr/lib
LIBS = -ltermcap
SRC = $(SDIR)main.c $(SDIR)init.c $(SDIR)iskey.c $(SDIR)select.c \
	  $(SDIR)bfunc.c $(SDIR)tputsfunc.c $(SDIR)isarrow.c $(SDIR)iskey2.c \
	  $(SDIR)signal.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo " - Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -I$(IDIR) $^ -o $(NAME) $(LIBTERM) $(LIBFT) $(LIBS)
	@echo "Done."

%.o:%.c
	@echo " - Creating $<..."
	@$(CC) $(CFLAGS) -I$(IDIR) $(LIBFT) $(LIBTERM) -c $< -o $@

clean:
	@echo " - Cleaning object files..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo " - Cleaning binary..."
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re
