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

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SDIR = sources/
ODIR = objects/
IDIR = includes/
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c \
	  ft_toupper.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	  ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	  ft_lstiter.c ft_lstmap.c ft_lstpushback.c ft_strcontains.c \
	  ft_match.c ft_lstsize.c ft_lstrev.c ft_avlnew.c ft_avldel.c \
	  ft_avladd.c ft_strcat.c ft_qsort.c
OBJ = $(SRC:.c=.o)
EXT = libft.h
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
