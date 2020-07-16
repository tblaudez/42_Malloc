# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tblaudez <tblaudez@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/06 17:45:13 by tblaudez      #+#    #+#                  #
#    Updated: 2020/07/16 14:03:34 by tblaudez      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
SRC= src/ft_digitcount.c src/ft_itoabase.c src/ft_max.c src/ft_memalloc.c \
src/ft_memcpy.c src/ft_memset.c src/ft_min.c src/ft_printf/ft_printf.c \
src/ft_printf/get_value1.c src/ft_printf/get_value2.c src/ft_putchar.c \
src/ft_putendl.c src/ft_putnbr.c src/ft_putstr.c \
src/ft_strcmp.c src/ft_strcpy.c src/ft_strdup.c src/ft_strjoinfree.c \
src/ft_strlen.c src/ft_strncmp.c src/ft_strncpy.c src/ft_strndup.c \
src/ft_strnew.c src/ft_strnjoinfree.c src/ft_strreplace.c \
src/ft_strreplaceone.c src/ft_strstr.c
OBJ= $(SRC:%.c=%.o)
CFLAGS= -Wall -Wextra -Werror
INCLUDE_FILE= include/libft.h
INCLUDE_DIR= -I include/

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE_FILE)
	ar rs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
