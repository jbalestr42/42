# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2016/03/29 15:00:34 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	particle_system
CC =	g++
FLAGS =	-O3 -Wall -Wextra -Werror -std=c++11
LIB =	-lglfw3 -lGL -lGLEW -lm -lXrandr -lXi -lXcursor -lXinerama -lX11 -lXxf86vm -lpthread -ldl -lOpenCL
SDIR =	sources/
ODIR =	objects/
IDIR =	includes/
SRC =	main.cpp \
		Matrix.cpp \
		Transformable.cpp \
		Quaternion.cpp \
		Windows.cpp \
		Vertex.cpp \
		Shader.cpp \
		Vector2.cpp \
		Vector3.cpp \
		Keyboard.cpp \
		Mouse.cpp \
		OpenCL.cpp \
		Color.cpp

INC =	Matrix.hpp \
		Transformable.hpp \
		Quaternion.hpp \
		Windows.hpp \
		Vertex.hpp \
		Shader.hpp \
		Vector2.hpp \
		Vector3.hpp \
		Math.hpp \
		Keyboard.hpp \
		Mouse.hpp \
		OpenCL.hpp \
		Color.hpp

OBJ =	$(SRC:.cpp=.o)
I =		$(addprefix $(IDIR), $(INC))
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -o $@ $^ -I $(IDIR) -I /usr/local/cuda/include $(LIB)
	@echo "-> Done !"

$(ODIR)%.o: $(SDIR)%.cpp $(I)
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@ -I $(IDIR) -I /usr/local/cuda/include

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
