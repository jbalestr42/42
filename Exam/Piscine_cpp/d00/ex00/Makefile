# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 15:51:56 by jbalestr          #+#    #+#              #
#    Updated: 2015/01/05 15:52:55 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	megaphone
CC =	g++
FLAGS =	-Wall -Wextra -Werror
SDIR =	sources/
ODIR =	objects/
SRC =	megaphone.cpp
OBJ =	$(SRC:.cpp=.o)
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -o $@ $^
	@echo "-> Done !"

$(ODIR)%.o: $(SDIR)%.cpp
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@ $(IDIR)

$(O): | ./objects
./objects:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)

re: fclean all
