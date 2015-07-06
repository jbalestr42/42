# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/22 15:58:47 by jbalestr          #+#    #+#              #
#    Updated: 2014/03/27 12:08:47 by jbalestr         ###   ########.fr        #
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
		vector_op.c vector_fun.c draw.c init_tab.c intersect.c \
		inter_mesh.c inter_mesh_2.c \
		init_scene.c diffuse.c normal.c specular.c init_screens.c \
		mouse_events1.c mouse_events2.c \
		reflection.c refraction.c save_ppm.c inv_matrix.c \
		matrix.c trans_matrix.c perlin_noise.c perlin_tools.c \
		init_items.c refresh_load.c display.c \
		anti_aliasing.c init_obj.c read_obj.c obj_file_helper.c \
		cell_shading.c perlin_effect.c checkerboard.c \
		color_op.c video.c menu.c check_events.c \
		ft_atod.c ft_atoi.c ft_info_1.c ft_info_2.c ft_light_1.c \
		ft_meshe_1.c ft_meshe_2.c ft_meshe_3.c ft_meshe_4.c ft_strsplit.c \
		init_info.c init_light.c init_mesh_2.c init_mesh.c parser.c tools_2.c \
		tools.c normal_2.c draw_images_and_loader.c key_events_2.c \
		post_process.c pixelise.c lst.c delete.c
OBJ =	$(SRC:.c=.o)
EXT =	includes/ray_tracer.h includes/objects.h includes/perlin.h \
		includes/parser.h includes/light.h includes/video.h
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
