# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2016/01/11 19:57:03 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	humanGL
CC =	g++
FLAGS =	-g -Wall -Wextra -Werror -std=c++11
#LIB =	-lm -lglfw3 -lGL -lGLEW -lGLU
#LIB =	-lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -pthread -lXi -ldl
LIB =	-lglfw3 -lGL -lGLEW -lm -lXrandr -lXi -lXcursor -lXinerama -lX11 -lXxf86vm -lpthread -ldl
SDIR =	sources/
ODIR =	objects/
IDIR =	includes/
SRC =	main.cpp \
		Matrix.cpp \
		Transformable.cpp \
		Quaternion.cpp \
		Windows.cpp \
		Mesh.cpp \
		Vertex.cpp \
		Shader.cpp \
		Vector2.cpp \
		Vector3.cpp \
		Animation.cpp \
		Node.cpp \
		Color.cpp
INC =	Matrix.hpp \
		Transformable.hpp \
		Quaternion.hpp \
		Windows.hpp \
		Mesh.hpp \
		Vertex.hpp \
		Shader.hpp \
		Vector2.hpp \
		Vector3.hpp \
		Math.hpp \
		Animation.hpp \
		IAnimatorBase.hpp \
		Animator.hpp \
		Node.hpp \
		Color.hpp
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
