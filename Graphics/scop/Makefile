.PHONY: all clean fclean re

NAME =	scop
CC =	gcc
LIB =	-L ../../.brew/Cellar/glfw3/3.1.2/lib -L gnl/ -L ../../.brew/Cellar/glew/1.13.0/lib -lm -lftgnl -lglfw3 -lGLEW -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
FLAGS =	-g -Wall -Wextra -Werror
SDIR =	sources/
ODIR =	objects/
IDIR =	-I includes/ -I gnl/includes -I ../../.brew/Cellar/glew/1.13.0/include -I ../../.brew/Cellar/glfw3/3.1.2/include
SRC =	main.c ft_strsplit.c list.c init.c setup_obj.c parsing_helpers.c process_obj_data.c \
		callback_functions.c matrix_transformation.c utils.c obj_data_function.c \
		matrix_math.c math.c mesh.c shader.c texture.c parsing.c input.c vector.c camera.c
OBJ =	$(SRC:.c=.o)
EXT =	includes/utils.h
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: lib $(NAME)

$(NAME): $(O)
	@echo "-> Creating $(NAME)..."
	@$(CC) $(FLAGS) -o $@ $^ $(IDIR) $(LIB)
	@echo "-> Done !"

$(ODIR)%.o: $(SDIR)%.c
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@ $(IDIR)

lib:
	@make -C gnl/

$(O): | ./objects
./objects:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning object files..."
	@rm -rf $(ODIR)
	@make clean -C gnl/

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)
	@make fclean -C gnl/

re: fclean all
