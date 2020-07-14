# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tblaudez <tblaudez@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/06 16:41:00 by tblaudez      #+#    #+#                  #
#    Updated: 2020/07/14 14:56:47 by tblaudez      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE= $(shell uname -m)_$(shell uname -s)
endif

NAME= libft_malloc_$(HOSTTYPE).so
LINKNAME= libft_malloc.so
SRC= src/blocks.c src/free.c src/get_zone_size.c src/is_size.c src/malloc.c\
src/realloc.c src/show_alloc_mem.c src/zones.c
OBJ= $(SRC:%.c=%.o)
CFLAGS= -Wall -Wextra -Werror -I include/ -I libft/include -g3
LIBFT= libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) -fPIC -shared $(OBJ) -o $(NAME)
	if [ ! -f "$(LINKNAME)" ]; then\
		ln -s $(NAME) $(LINKNAME);\
	fi;

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
