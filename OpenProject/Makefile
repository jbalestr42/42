# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 12:08:17 by jbalestr          #+#    #+#              #
#    Updated: 2015/03/10 14:26:23 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re dep

NAME	= a.out
RELEASE	= -DNDEBUG
DEBUG	= -g
CXX		= clang++ $(DEBUG)
FLAGS	= -Wall -Wextra -w -std=c++0x -O3
UNAME	= $(shell uname)

ifeq ($(UNAME), Linux)
	LIB	= -L Lib/SFML/Linux/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL
else
	LIB	= -L Lib/SFML/MacOSX/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -framework OpenGL
endif
IDIR	= -ILib/SFML/include -I./Lib -I./ -IMain -IGameObject -IOcto -IScenes
DEPDIR	= -Y -IMain -IGameObject -IOcto -IScenes
ODIR	= Objects/

SRC		= $(wildcard Main/*.cpp) $(wildcard Octo/*.cpp) $(wildcard GameObject/*.cpp) $(wildcard Scenes/*.cpp)
OBJ		= $(patsubst %.cpp, $(ODIR)%.o, $(SRC))

all: $(NAME)

dep: depend re

data:
	@make -C DataConverter create

$(NAME): system $(OBJ)
	@echo "-> Creating $(NAME)..."
	@$(CXX) $(FLAGS) -o $@ $(OBJ) $(LIB)
	@echo "-> Done !"
	@echo "-> Export environnement variable..."
	@echo "-> Don't forget to export environnement variable"
	@echo "export LD_LIBRARY_PATH=`pwd`/Lib/SFML/MacOSX/lib"

system:
	@echo "-> Detecting $(UNAME) system..."

Objects/%.o: %.cpp
	@echo "-> Compiling $<..."
	@$(CXX) $(FLAGS) -c $< -o $@ $(IDIR)

depend:
	@echo "-> Creating dependencies..."
	@makedepend $(DEPDIR) -p$(ODIR) -- $(FLAGS) -- $(SRC)
	@rm -f Makefile.bak

$(OBJ): | $(ODIR)
$(ODIR):
	@mkdir $@
	@mkdir $@/Lib
	@mkdir $@/Main
	@mkdir $@/Octo
	@mkdir $@/GameObject
	@mkdir $@/Scenes

clean:
	@echo "-> Cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)

re: fclean $(NAME)
# DO NOT DELETE

Objects/Main/AnimatedSprite.o: Main/AnimatedSprite.hpp Main/Sprite.hpp
Objects/Main/AnimatedSprite.o: Main/ResourcesManager.hpp
Objects/Main/AnimatedSprite.o: Main/DefineResources.hpp
Objects/Main/FrameRate.o: Main/FrameRate.hpp Main/Graph.hpp
Objects/Main/FrameRate.o: Main/ResourcesManager.hpp Main/DefineResources.hpp
Objects/Main/GameManager.o: Main/GameManager.hpp Scenes/SceneBase.hpp
Objects/Main/GameManager.o: Main/ResourcesManager.hpp
Objects/Main/GameManager.o: Main/DefineResources.hpp Main/Options.hpp
Objects/Main/GameManager.o: Main/FrameRate.hpp Main/Graph.hpp
Objects/Main/GameManager.o: Octo/OctoLogger.hpp Octo/OctoFile.hpp
Objects/Main/GameManager.o: Scenes/SceneNoise.hpp Main/Sprite.hpp
Objects/Main/GameManager.o: GameObject/TileMapManager.hpp
Objects/Main/GameManager.o: GameObject/TileMap.hpp Octo/Matrix.hpp
Objects/Main/GameManager.o: Octo/Matrix.hxx
Objects/Main/Graph.o: Main/Graph.hpp Main/ResourcesManager.hpp
Objects/Main/Graph.o: Main/DefineResources.hpp
Objects/Main/main.o: Main/GameManager.hpp Scenes/SceneBase.hpp
Objects/Main/Options.o: Main/Options.hpp Octo/OctoFile.hpp
Objects/Main/Options.o: Octo/OctoLogger.hpp Octo/OctoFile.hpp
Objects/Main/ResourcesManager.o: Main/ResourcesManager.hpp
Objects/Main/ResourcesManager.o: Main/DefineResources.hpp Octo/OctoLogger.hpp
Objects/Main/ResourcesManager.o: Octo/OctoFile.hpp
Objects/Main/Sprite.o: Main/Sprite.hpp
Objects/Octo/OctoFile.o: Octo/OctoFile.hpp
Objects/Octo/OctoLogger.o: Octo/OctoLogger.hpp Octo/OctoFile.hpp
Objects/Octo/OctoNoise.o: Octo/OctoNoise.hpp
Objects/GameObject/GameObject.o: GameObject/GameObject.hpp
Objects/GameObject/GameObject.o: Main/ResourcesManager.hpp
Objects/GameObject/GameObject.o: Main/DefineResources.hpp
Objects/GameObject/Player.o: GameObject/Player.hpp GameObject/GameObject.hpp
Objects/GameObject/TileMap.o: GameObject/TileMap.hpp Octo/Matrix.hpp
Objects/GameObject/TileMap.o: Octo/Matrix.hxx Octo/OctoNoise.hpp
Objects/GameObject/TileMapManager.o: GameObject/TileMapManager.hpp
Objects/GameObject/TileMapManager.o: GameObject/TileMap.hpp Octo/Matrix.hpp
Objects/GameObject/TileMapManager.o: Octo/Matrix.hxx
Objects/GameObject/TileMapManager.o: Main/ResourcesManager.hpp
Objects/GameObject/TileMapManager.o: Main/DefineResources.hpp
Objects/Scenes/SceneBase.o: Scenes/SceneBase.hpp
Objects/Scenes/SceneNoise.o: Scenes/SceneNoise.hpp Scenes/SceneBase.hpp
Objects/Scenes/SceneNoise.o: Main/Sprite.hpp GameObject/TileMapManager.hpp
Objects/Scenes/SceneNoise.o: GameObject/TileMap.hpp Octo/Matrix.hpp
Objects/Scenes/SceneNoise.o: Octo/Matrix.hxx Main/ResourcesManager.hpp
Objects/Scenes/SceneNoise.o: Main/DefineResources.hpp Octo/OctoNoise.hpp
