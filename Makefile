# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 18:05:57 by dbauduin          #+#    #+#              #
#    Updated: 2017/05/08 21:00:39 by dbauduin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

OBJ =	objs/main.o\
		objs/setup.o\
		objs/act_windows.o\

all: $(NAME)

$(NAME): objs $(OBJ)
	@make -C libft/ fclean && make -C libft/
	@gcc -o $(NAME) $(OBJ) -framework OpenGL -framework AppKit libft/libft.a minilibx/libmlx.a
	@echo "\033[32mFdF compiled	[ ✔ ]\033[0m"

objs:
	@mkdir objs

objs/%.o: srcs/%.c
	@gcc -Wall -Wextra -Werror -I libft/includes -I minilibx -o $@ -c $<

clean:
	@rm -rf obj/
	@make -C libft/ fclean
	@rm -Rf objs
	@echo "\033[32mFdF cleaned	[ ✔ ]\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all]]]]"
