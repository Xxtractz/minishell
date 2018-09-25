# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 09:09:40 by mbaloyi           #+#    #+#              #
#    Updated: 2018/08/20 09:09:41 by mbaloyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./printf/ all
	@echo "\033[1;32m libft.a && libftprintf.a created"

clean :
	@make -C ./printf/ all
	@echo "\033[1;31m objects deleted"

fclean: clean
	@make -C ./printf/ fclean
	@echo "\033[1;31m objects and .a files deleted"

re: fclean all

norm :
	@make -C ./printf/ norm
	@echo "\033[0;32mWill auto clear in 10 secs"
	@sleep 10
	clear
