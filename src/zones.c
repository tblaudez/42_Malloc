/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zones.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 14:42:01 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/21 13:37:00 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdbool.h>
#include <stdlib.h>
#include "malloc.h"
#include "libft.h"

static void		initialize_zone(t_zone *zone, size_t zone_size, const t_kind kind)
{
	zone->kind = kind;
	zone->next = NULL;
	zone->size = zone_size;
	zone->block = (t_block*)((char*)zone + sizeof(t_zone));
	zone->block->ptr = (void*)((char*)zone->block + sizeof(t_block));
	zone->block->true_size = zone_size - (sizeof(t_zone) + sizeof(t_block));
	zone->block->alloc_size = 0;
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

t_zone			*create_new_zone(size_t alloc_size, const t_kind kind)
{
	t_zone			*zone;
	size_t	(*const size_function[3])(size_t size) = {&get_tiny_zone_size, &get_small_zone_size, &get_large_zone_size};
	const size_t	zone_size = size_function[kind](alloc_size);

	if ((zone = mmap(NULL, zone_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
	{
		ft_putendl("malloc() - mmap error");
		exit(1);
	}
	initialize_zone(zone, zone_size, kind);
	append_new_zone(zone);
	return (zone);
}
