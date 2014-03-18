# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/22 15:58:47 by jbalestr          #+#    #+#              #
#    Updated: 2014/03/13 11:41:46 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	Ray_Tracer
CC =	gcc
LIB =	-L gnl/ -L /usr/X11/lib/ -lmlx -lXext -lX11 -lm -lftgnl
FLAGS =	-g -Wall -Wextra -Werror
SDIR =	sources/
ODIR =	objects/
IDIR =	-I includes/ -I /usr/X11/include/ -I gnl/includes
SRC =	main.c init.c events.c key_events.c helpers.c init_keys.c \
		vector_op.c vector_fun.c draw.c init_tab.c intersect.c inter_mesh.c \
		init_scene.c diffuse.c normal.c specular.c init_screens.c \
		mouse_events.c reflection.c refraction.c save_ppm.c inv_matrix.c \
		matrix.c trans_matrix.c perlin_noise.c perlin_tools.c \
		init_choose_scene.c init_items.c
OBJ =	$(SRC:.c=.o)
EXT =	includes/ray_tracer.h includes/objects.h includes/perlin.h
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: lib $(NAME)

$(NAME): $(O) $(EXT)
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
