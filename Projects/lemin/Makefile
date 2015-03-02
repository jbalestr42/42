# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 02:20:27 by tcharlat          #+#    #+#              #
#    Updated: 2014/02/21 14:04:37 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =	lem-in
CC =	gcc
LIB =	-L gnl/ -L libft -lft -lftgnl
FLAGS =	-g -Wall -Wextra -Werror
SDIR =	sources/
ODIR =	objects/
IDIR =	-I includes/ -I gnl/includes -I libft/includes
SRC =	main.c read_std.c init.c init_graph.c read_ants.c read_rooms.c \
		read_path.c define_path.c
OBJ =	$(SRC:.c=.o)
EXT =	includes/lemin.h
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
	@make -C libft/

$(O): | ./objects
./objects:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning object files..."
	@rm -rf $(ODIR)
	@make clean -C gnl/
	@make clean -C libft/

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)
	@make fclean -C gnl/
	@make fclean -C libft/

re: fclean all
