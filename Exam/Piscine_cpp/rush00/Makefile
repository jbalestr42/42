# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2015/01/11 22:01:50 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	ft_retro
CC =	g++
FLAGS =	-Wall -Wextra -Werror -std=c++98
LIB =	-lncurses
SDIR =	sources/
ODIR =	objects/
IDIR =	includes/
SRC =	main.cpp GameManager.cpp GameEntity.cpp Player.cpp Weapon.cpp Model.cpp \
		FlowerGun.cpp Bullet.cpp Enemy.cpp Spawner.cpp Decor.cpp Bonus.cpp
INC =	GameManager.hpp GameEntity.hpp Player.hpp Weapon.hpp Model.hpp \
		FlowerGun.hpp Bullet.hpp Enemy.hpp Spawner.hpp Decor.hpp Bonus.hpp
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
