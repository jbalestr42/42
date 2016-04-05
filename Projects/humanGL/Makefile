# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2016/03/07 14:07:08 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	humanGL
CC =	g++
FLAGS =	-g -Wall -Wextra -Werror -std=c++11
#LIB =	-lglfw3 -lGL -lGLEW -lm -lXrandr -lXi -lXcursor -lXinerama -lX11 -lXxf86vm -lpthread -ldl -framework GLFW
LIB =	-L ../../.brew/Cellar/glfw3/3.1.2/lib -L../../.brew/Cellar/glew/1.13.0/lib -lglfw3 -lGLEW -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
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
		Keyboard.cpp \
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
		AAnimator.hpp \
		AddAnimator.hpp \
		SetAnimator.hpp \
		LerpAnimator.hpp \
		CerpAnimator.hpp \
		Keyboard.hpp \
		Node.hpp \
		Color.hpp
OBJ =	$(SRC:.cpp=.o)
I =		$(addprefix $(IDIR), $(INC))
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -o $@ $^ -I ../../.brew/Cellar/glfw3/3.1.2/include/ -I ../../.brew/Cellar/glew/1.13.0/include -I $(IDIR) $(LIB)
	@echo "-> Done !"

$(ODIR)%.o: $(SDIR)%.cpp $(I)
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@ -I $(IDIR) -I ../../.brew/Cellar/glfw3/3.1.2/include/ -I ../../.brew/Cellar/glew/1.13.0/include

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
