/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 17:05:44 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/16 15:04:08 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdbool.h>
# include "libft.h"

# define ALLOCATION_PER_ZONE	128
# define TINY_SIZE				4096
# define SMALL_SIZE				8192

enum	e_kind {
	TINY, SMALL, LARGE
};

struct							s_block
{
	void						*ptr;
	char						free;
	size_t						size;
	size_t						_large_real_size;
	struct s_block				*next;
} __attribute__((aligned(16)));
typedef struct s_block			t_block;

struct							s_zone
{
	t_block						*block;
	size_t						size;
	enum e_kind					kind;
	struct s_zone				*next;
} __attribute__((aligned(16)));
typedef struct s_zone			t_zone;

extern t_zone					*g_malloc;

/*
**	blocks.c
*/
t_block							*get_suitable_block(size_t size\
, const enum e_kind kind);
void							find_block_by_ptr(t_zone **zptr\
, t_block **bptr, void *ptr);
void							initialize_block(t_block *block\
, size_t block_size);

/*
**	free.c
*/
void							free(void *ptr);

/*
**	get_zone_size.c
*/
size_t							get_tiny_zone_size(void);
size_t							get_small_zone_size(void);
size_t							get_large_zone_size(size_t size);

/*
**	is_size.c
*/
bool							is_tiny(size_t size);
bool							is_small(size_t size);
bool							is_large(size_t size);

/*
**	malloc.c
*/
void							*malloc(size_t size);

/*
**	realloc.c
*/
void							*realloc(void *ptr, size_t size);

/*
**	show_alloc_mem.c
*/
void							show_alloc_mem(void);

/*
**	zones.c
*/
t_zone							*create_new_zone(size_t size\
, const enum e_kind kind);

#endif
