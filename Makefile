# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 16:41:00 by tblaudez          #+#    #+#              #
#    Updated: 2020/07/07 18:36:00 by tblaudez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE= $(shell uname -m)_$(shell uname -s)
endif

NAME= libft_malloc_$(HOSTTYPE).so
LINKNAME= libft_malloc.so
SRC= src/zones.c src/utils.c src/malloc.c src/free.c src/realloc.c
OBJ= $(SRC:%.c=%.o)
CFLAGS= -Wall -Wextra -Werror -I include/ -I libft/include -g3
LIBFT= libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) -fPIC -shared $(OBJ) -o $(NAME)
	if [ ! -f "$(LINKNAME)" ]; then \
		ln -s $(NAME) $(LINKNAME); \
	fi;
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) src/main.c -o malloc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME) $(LINKNAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re