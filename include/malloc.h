/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 17:05:44 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/08/27 10:11:21 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdbool.h>
# include <stdint.h>
# include <stddef.h>
# include <pthread.h>

# define ALLOC_PER_ZONE	112
# define TINY_MAX		1024
# define SMALL_MAX		10240

typedef enum e_kind		t_kind;
enum	e_kind {
	TINY, SMALL, LARGE, INVALID
};

typedef struct s_block	t_block;
struct					s_block
{
	void				*ptr;
	unsigned			free:1;
	uint32_t			alloc_size;
	uint32_t			true_size;
	t_block				*next;
} __attribute__((aligned(16)));

typedef struct s_zone	t_zone;
struct					s_zone
{
	t_kind				kind;
	uint32_t			size;
	t_block				*block;
	t_zone				*next;
} __attribute__((aligned(16)));

t_block					*get_suitable_block(size_t size, const t_kind kind);
void					initialize_block(t_block *block, size_t block_size);
void					find_block_by_ptr(t_zone **zptr, t_block **bptr,\
							void *ptr);

t_zone					*create_new_zone(size_t size, const t_kind kind);

size_t					get_tiny_zone_size();
size_t					get_small_zone_size();
size_t					get_large_zone_size(size_t size);

bool					is_tiny(size_t size);
bool					is_small(size_t size);
bool					is_large(size_t size);

void					free(void *ptr);
void					*malloc(size_t size);
void					*calloc(size_t count, size_t size);
void					*realloc(void *ptr, size_t size);

void					show_alloc_mem(void);
void					show_alloc_mem_hex(void);

extern t_zone			*g_malloc;
extern pthread_mutex_t	g_mutex;

#endif
