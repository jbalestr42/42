# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2015/03/10 14:30:48 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	= data_converter
CXX		= clang++
FLAGS	= -Wall -Wextra -w -std=c++0x
UNAME	= $(shell uname)

ifeq ($(UNAME), Linux)
	LIB = -L ../Lib/SFML/Linux/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL
else
	LIB = -L ../Lib/SFML/MacOSX/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -framework GLUT -framework OpenGL
endif
IDIR	= -I../Lib/SFML/include -I../ -I../Main -I../GameObject -I../Octo

SRC	= ../Main/ResourcesManager.cpp ../Octo/OctoFile.cpp ../Octo/OctoLogger.cpp main.cpp

all: $(NAME)

create: $(NAME)
	@./create.sh
	@make fclean

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@$(CXX) $(FLAGS) -o $@ $(SRC) $(LIB) $(IDIR)
	@echo "-> Done !"

clean:
	@echo "-> Cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)

re: fclean $(NAME)
