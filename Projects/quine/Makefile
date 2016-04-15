.PHONY: all clean fclean re

NAME =	Colleen
NAME1 =	Grace
NAME2 =	Sully
FLAGS =	-Wall -Wextra -Werror

all: $(NAME) $(NAME1) $(NAME2)

$(NAME):
	@clang $(FLAG) $(NAME).c -o $(NAME)

$(NAME1):
	@clang $(FLAG) $(NAME1).c -o $(NAME1)

$(NAME2):
	@clang $(FLAG) $(NAME2).c -o $(NAME2)

clean:

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all
