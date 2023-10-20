# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 12:31:17 by chruhin           #+#    #+#              #
#    Updated: 2023/01/11 18:20:12 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c ft_put_char.c ft_put_nbr.c ft_put_percent.c ft_put_str.c \
		ft_check_specifier.c ft_put_addres.c ft_put_hex_low.c ft_put_hex_upp.c \
		ft_put_unsigned.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): all

all:
		$(CC) $(CFLAGS) -c $(SOURCES)
		ar -rcs $(NAME) $(OBJECTS)

clean:
		/bin/rm -f $(OBJECTS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# https://cs.colby.edu/maxwell/courses/tutorials/maketutor/
# 