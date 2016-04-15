# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2015/01/14 13:41:10 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	array
CC =	g++
FLAGS =	-Wall -Wextra -Werror -std=c++98
LIB =	-lncurses
SDIR =	sources/
ODIR =	objects/
IDIR =	includes/
SRC =	main.cpp
INC =	Array.hpp
OBJ =	$(SRC:.cpp=.o)
I =		$(addprefix $(IDIR), $(INC))
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -o $@ $^ -I $(IDIR) $(LIB)
	@echo "-> Done !"

$(ODIR)%.o: $(SDIR)%.cpp $(I)
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@ -I $(IDIR)

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
