# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 11:16:40 by mbaloyi           #+#    #+#              #
#    Updated: 2018/09/13 11:16:46 by mbaloyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	shlib.a

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

LIB_A	=	./libft/printf/libftprintf.a

SRCS	=	

OBJS	=	

all: $(NAME)

$(NAME) : 
	@make -C ./libft all
	$(CC) minishell.c -o minishell $(FLAGS) $(LIB_A) 
	
clean:
	@make -C ./libft clean
	@rm -rf $(OBJS)
	
fclean : clean
	@make -C ./libft fclean
	@rm -rf ft_ls
	@/bin/rm -rf $(NAME)

re : fclean all

norm :
	@make -C ./libft norm
	@echo "\033[0;32mWill auto clear in 10 secs\033[0m"
	@sleep 10
	clear