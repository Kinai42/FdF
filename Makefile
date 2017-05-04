# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 18:05:57 by dbauduin          #+#    #+#              #
#    Updated: 2017/05/04 17:42:35 by dbauduin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

FLAGS	= -Wall -Wextra

CC		= gcc

INCS	= includes -I libft

SOURCE	= fdf.c

OBJS	= $(SRCS:.c=.o)


RED		=	@echo "\033[32m[✓] FdF -> Clean\n\033[0m"
GREEN	=	@echo "\033[32m[✓] FdF -> Compile\033[0m"

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -o $(NAME) $(SOURCE) -lmlx -framework OpenGL -framework AppKit
	$(GREEN)

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	$(RED)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
