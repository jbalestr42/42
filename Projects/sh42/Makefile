#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/22 18:09:44 by hjeannin          #+#    #+#              #
#    Updated: 2014/06/25 19:08:20 by jbalestr         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_PATH	=	src/
OBJ_PATH	=	obj/

SRCS		=	$(shell ls $(SRC_PATH) | grep .c$$)
OBJS		=	$(patsubst %.c, $(OBJ_PATH)%.o,$(SRCS))

LNAME		=	libft.a
LDIR		=	libft/
HEADER		=	-I./includes -I./$(LDIR)includes
FLAGS		=	-g -Wall -Wextra -Werror
NAME		=	42sh

CC			=	gcc

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LDIR)
	@$(CC) $(FLAGS) $(HEADER) $(LDIR)$(LNAME) $(OBJS) -o $(NAME) -L /usr/lib -ltermcap

$(patsubst %, $(OBJ_PATH)%,%.o): $(SRC_PATH)$(notdir %.c)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(FLAGS) $(HEADER) "$<" -o "$@"

clean:
	@make -C $(LDIR) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LDIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
