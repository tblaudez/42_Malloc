/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 12:37:13 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 12:51:36 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "malloc.h"

t_zone			*g_malloc = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

static t_kind	get_kind(size_t alloc_size)
{
	if (is_tiny(alloc_size))
		return (TINY);
	else if (is_small(alloc_size))
		return (SMALL);
	else if (is_large(alloc_size))
		return (LARGE);
	return (INVALID);
}

void			*malloc(size_t size)
{
	t_kind				kind;
	t_block				*block;

	pthread_mutex_lock(&g_mutex);
	kind = get_kind(size);
	if (kind == INVALID)
	{
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	block = get_suitable_block(size, kind);
	block->free = false;
	pthread_mutex_unlock(&g_mutex);
	return (block->ptr);
}
