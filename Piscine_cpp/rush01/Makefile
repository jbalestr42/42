# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2015/02/11 16:36:46 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	BoringProject
CC =	g++
FLAGS =	-Wall -Wextra -Werror -std=c++98
LIB =	-F ~/Library/Frameworks -framework SFML -framework sfml-graphics -framework sfml-window -framework sfml-system -I lib/includes -lncurses
SDIR =	sources/
ODIR =	objects/
IDIR =	includes/
SRC =	main.cpp BoringInfos.cpp CPUModule.cpp ClockModule.cpp HostModule.cpp \
		IInfosGetter.cpp IInfosSetter.cpp IMonitorDisplay.cpp IMonitorModule.cpp \
		OSModule.cpp RAMModule.cpp SFMLDisplay.cpp Graph.cpp NcursesDisplay.cpp
INC =	BoringInfos.hpp CPUModule.hpp ClockModule.hpp HostModule.hpp \
		IInfosGetter.hpp IInfosSetter.hpp IMonitorDisplay.hpp IMonitorModule.hpp \
		OSModule.hpp RAMModule.hpp SFMLDisplay.hpp Graph.hpp NcursesDisplay.hpp
OBJ =	$(SRC:.cpp=.o)
I =		$(addprefix $(IDIR), $(INC))
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

$(NAME): $(O)
	@cp -r lib/Frameworks ~/Library
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -o $@ $^ -I $(IDIR) $(LIB)
	@echo "-> Done !"
	@export DYLD_LIBRARY_PATH=~/Downloads/SFML-2.1-osx-gcc-universal/lib

$(ODIR)%.o: $(SDIR)%.cpp $(I)
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@ ${LIB} -I $(IDIR)

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
