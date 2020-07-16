# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tblaudez <tblaudez@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/06 16:41:00 by tblaudez      #+#    #+#                  #
#    Updated: 2020/07/16 14:19:30 by tblaudez      ########   odam.nl          #
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
CFLAGS= -Wall -Wextra -Werror
INCLUDE_FILE= include/malloc.h
INCLUDE_DIR= -I include/ -I libft/include
LIBFT= libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(OBJ) $(INCLUDE_FILE)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -fPIC -shared -L libft/ -l ft $(OBJ) -o $(NAME)
	ln -sf $(NAME) $(LINKNAME);
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME) $(LINKNAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
