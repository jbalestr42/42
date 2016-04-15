.PHONY: all clean fclean re

NAME =	lem-in
CC =	gcc
LIB =	-L gnl/ -lftgnl
FLAGS =	-g -Wall -Wextra -Werror
SDIR =	sources/
ODIR =	objects/
IDIR =	-I includes/ -I gnl/includes
SRC =	main.c dijkstra.c graph.c min_heap.c parsing.c parsing_helper.c ft_strsplit.c \
		ft_splitwhite.c parsing_room.c parsing_edge.c parsing_ant.c libft.c room.c \
		parsing_commands.c print_result.c libft_print.c destroy_graph.c \
		print_result2.c
OBJ =	$(SRC:.c=.o)
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
