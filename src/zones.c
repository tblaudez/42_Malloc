/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zones.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 14:42:01 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/16 15:01:40 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdbool.h>
#include "malloc.h"

static size_t	get_zone_size(size_t size, const enum e_kind kind)
{
	if (kind == TINY)
		return (get_tiny_zone_size());
	else if (kind == SMALL)
		return (get_small_zone_size());
	else
		return (get_large_zone_size(size));
}

static void		initialize_zone(t_zone *zone, size_t size\
, const enum e_kind kind)
{
	zone->kind = kind;
	zone->next = NULL;
	zone->size = get_zone_size(size, kind);
	zone->block = (t_block*)((char*)zone + sizeof(t_zone));
	zone->block->ptr = (void*)((char*)zone->block + sizeof(t_block));
	zone->block->size = zone->size - (sizeof(t_zone) + sizeof(t_block));
	zone->block->free = true;
	zone->block->next = NULL;
}

static void		append_new_zone(t_zone *new)
{
	t_zone	*zone;

	if (g_malloc == NULL)
	{
		g_malloc = new;
		return ;
	}
	zone = g_malloc;
	while (zone->next)
		zone = zone->next;
	zone->next = new;
}

t_zone			*create_new_zone(size_t size, const enum e_kind kind)
{
	t_zone	*zone;
	
	if (kind == TINY)
		zone = mmap(NULL, get_tiny_zone_size(), PROT_READ | PROT_WRITE\
		, MAP_ANON | MAP_PRIVATE, -1, 0);
	else if (kind == SMALL)
		zone = mmap(NULL, get_small_zone_size(), PROT_READ | PROT_WRITE\
		, MAP_ANON | MAP_PRIVATE, -1, 0);
	else
		zone = mmap(NULL, get_large_zone_size(size), PROT_READ | PROT_WRITE\
		, MAP_ANON | MAP_PRIVATE, -1, 0);
	initialize_zone(zone, size, kind);
	append_new_zone(zone);
	return (zone);
}




