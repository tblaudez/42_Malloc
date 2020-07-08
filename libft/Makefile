# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 17:45:13 by tblaudez          #+#    #+#              #
#    Updated: 2020/07/08 14:37:39 by tblaudez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
SRC= src/ft_memalloc.c src/ft_memcpy.c src/ft_memset.c src/ft_putchar.c \
src/ft_putendl.c src/ft_putnbr.c src/ft_putstr.c src/ft_strcmp.c \
src/ft_strcpy.c src/ft_strjoin.c src/ft_strlen.c src/ft_strncpy.c
OBJ= $(SRC:%.c=%.o)
CFLAGS= -Wall -Wextra -Werror -I include/ -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar rs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re