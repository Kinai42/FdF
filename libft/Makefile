# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/16 02:53:24 by dbauduin          #+#    #+#              #
#    Updated: 2017/05/08 21:10:56 by dbauduin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-I./includes -Wall -Werror -Wextra

RM		=	/bin/rm

NAME	=	libft.a

SRC		=	get_next_line.c\
			ft_isalpha.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_isdigit.c\
			ft_atoi.c\
			ft_strcat.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdup.c\
			ft_strlen.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strstr.c\
			ft_strlcat.c\
			ft_memset.c\
			ft_memcpy.c\
			ft_bzero.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memmove.c\
			ft_strchr.c\
			ft_strnstr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_strrchr.c\
			ft_putnbr_fd.c\
			ft_putendl_fd.c\
			ft_putstr_fd.c\
			ft_putchar_fd.c\
			ft_putnbr.c\
			ft_putendl.c\
			ft_putstr.c\
			ft_putchar.c\
			ft_itoa.c\
			ft_strsplit.c\
			ft_strtrim.c\
			ft_strjoin.c\
			ft_strsub.c\
			ft_strnequ.c\
			ft_strequ.c\
			ft_strmapi.c\
			ft_strmap.c\
			ft_striteri.c\
			ft_striter.c\
			ft_strclr.c\
			ft_strdel.c\
			ft_strnew.c\
			ft_memdel.c\
			ft_memalloc.c\
			ft_cleaner.c\
			ft_strrlen.c\
			ft_digitlen.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_isupper.c\
			ft_islower.c\
			ft_str_capitalize.c\
			ft_tablen.c\

OBJ		=	$(subst .c,.o,$(SRC))

$(NAME)	:
	@$(CC) -c $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(RM) -f $(OBJ)

all		:	$(NAME)

clean	:
	@$(RM) -rf $(OBJ)

fclean	:	clean
	@$(RM) -rf $(NAME)

re		:	fclean all
