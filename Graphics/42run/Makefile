# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2016/04/04 17:41:30 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	42run
CC =	g++
FLAGS =	-g -Wall -Wextra -Werror -std=c++11
#LIB =	-lglfw3 -lGL -lGLEW -lm -lXrandr -lXi -lXcursor -lXinerama -lX11 -lXxf86vm -lpthread -ldl lib/libassimp.so
LIB =	-L $(DEVIL)/lib -L $(GLFW)/lib -L $(GLEW)/lib -L $(ASSIMP)/lib -lIL -lglfw3 -lGLEW -lassimp -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
SDIR =	sources/
ODIR =	objects/
IDIR =	includes/
SRC =	main.cpp \
		Matrix.cpp \
		Transformable.cpp \
		Quaternion.cpp \
		Windows.cpp \
		Mesh.cpp \
		ResourceManager.cpp \
		Vertex.cpp \
		Shader.cpp \
		Vector2.cpp \
		Vector3.cpp \
		Keyboard.cpp \
		Texture.cpp \
		AnimatedTexture.cpp \
		Room.cpp \
		RoomStraight.cpp \
		RoomStraightLeft.cpp \
		RoomManager.cpp \
		Factory.cpp \
		Player.cpp \
		HUD.cpp \
		Color.cpp

INC =	Matrix.hpp \
		Transformable.hpp \
		Quaternion.hpp \
		Windows.hpp \
		Mesh.hpp \
		ResourceManager.hpp \
		Vertex.hpp \
		Shader.hpp \
		Vector2.hpp \
		Vector3.hpp \
		Math.hpp \
		Keyboard.hpp \
		Texture.hpp \
		AnimatedTexture.hpp \
		Room.hpp \
		RoomStraight.hpp \
		RoomStraightLeft.hpp \
		RoomManager.hpp \
		Factory.hpp \
		Player.hpp \
		HUD.hpp \
		Color.hpp

OBJ =	$(SRC:.cpp=.o)
I =		$(addprefix $(IDIR), $(INC))
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -o $@ $^ -I $(DEVIL)/include/ -I $(GLFW)/include/ -I $(GLEW)/include/ -I $(ASSIMP)/include/assimp -I $(IDIR) $(LIB)
	@echo "-> Done !"

$(ODIR)%.o: $(SDIR)%.cpp $(I)
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@ -I $(IDIR) -I $(DEVIL)/include/ -I $(GLFW)/include/ -I $(GLEW)/include/ -I $(ASSIMP)/include/assimp

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
