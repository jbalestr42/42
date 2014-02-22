# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 11:57:09 by jbalestr          #+#    #+#              #
#    Updated: 2014/02/08 13:47:25 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C client
	@make -C server

clean:
	@make clean -C client
	@make clean -C server

fclean: clean
	@make fclean -C client
	@make fclean -C server

re: fclean all

.PHONY: all clean fclean re
