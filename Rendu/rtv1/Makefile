# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 02:20:27 by tcharlat          #+#    #+#              #
#    Updated: 2015/01/05 17:56:13 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	RTv1
CC =	gcc
LIB =	-L gnl/ -L /usr/X11/lib/ -lmlx -lXext -lX11 -lm -lftgnl
FLAGS =	-g -Wall -Wextra -Werror
SDIR =	sources/
ODIR =	objects/
IDIR =	-I includes/ -I /usr/X11/include/ -I gnl/includes
SRC =	main.c init.c init_events.c init_image.c events.c key_events.c \
		init_types.c compute_inter.c draw.c math.c math_vec.c helpers.c \
		init_scene.c inter_object.c read_color.c read_objects.c \
		normal_objects.c compute_diffuse.c init_obj.c read_obj.c ft_atod.c
OBJ =	$(SRC:.c=.o)
EXT =	includes/ray_tracer.h includes/objects.h includes/obj_file.h
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
