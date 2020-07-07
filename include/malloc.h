/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:05:44 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 18:47:39 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MALLOC_H
# define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft.h"

# define ALLOCATION_PER_ZONE	128
# define PAGE_SIZE				getpagesize()
# define MMAP(x)				mmap(NULL, x, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)

# define TINY_SIZE				512
# define SMALL_SIZE				1024
# define ISTINY(x)				(x <= TINY_SIZE)
# define ISSMALL(x)				(x > TINY_SIZE && x <= SMALL_SIZE)
# define ISLARGE(x)				(x > SMALL_SIZE)

# define ALIGN_PAGE(x)			(((x / PAGE_SIZE) + 1) * PAGE_SIZE)
# define TINY_ZONE_SIZE			ALIGN_PAGE((((TINY_SIZE + sizeof(t_block)) * ALLOCATION_PER_ZONE) + sizeof(t_zone)))
# define SMALL_ZONE_SIZE		ALIGN_PAGE((((SMALL_SIZE + sizeof(t_block)) * ALLOCATION_PER_ZONE) + sizeof(t_zone)))
# define LARGE_ZONE_SIZE(x)		ALIGN_PAGE((x + sizeof(t_block) + sizeof(t_zone)))

enum e_kind {
	TINY, SMALL, LARGE
};

typedef struct					s_block
{
	void			*ptr;
	char			free;
	struct s_block	*next;
} __attribute__((aligned(16)))	t_block;

typedef struct					s_zone
{
	t_block			*blocks;
	size_t			size;
	enum e_kind		kind;
	struct s_zone	*next;
} __attribute__((aligned(16)))	t_zone;

extern t_zone					*g_malloc;


/*
** malloc.c 
*/
void							*ft_malloc(size_t size);

/*
** free.c 
*/
void							ft_free(void *ptr);

/*
** realloc.c 
*/
void							*ft_realloc(void *ptr, size_t size);

/*
** zones.c 
*/
t_zone							*create_new_zone(size_t size, const enum e_kind kind);

/*
** utils.c 
*/
void							append_new_zone(t_zone *new);
void							delete_zone(t_zone *zone);
t_block							*find_free_block(t_block *block);
size_t							get_zone_size(size_t size, const enum e_kind kind);
t_block							*get_suitable_block(size_t size, const enum e_kind kind);
void							find_block_by_ptr(t_zone **zptr, t_block **bptr, void *ptr);

/*
** show_alloc_mem.c 
*/
void							show_alloc_mem();


#endif