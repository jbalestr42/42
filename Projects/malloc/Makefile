.PHONY: all clean fclean re

NAME =	malloc
CC =	gcc
LIB =	
FLAGS =	-g -Wall -Wextra -Werror
SDIR =	sources/
ODIR =	objects/
IDIR =	-I includes/
SRC =	main.c
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
