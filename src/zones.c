/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:42:01 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 17:09:54 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	initialize_block(t_block *block, size_t block_size)
{
	int	i;

	i = ALLOCATION_PER_ZONE;
	while (i--)
	{
		block->free = true;
		block->ptr = (void*)((char*)block + sizeof(t_block));
		if (i == 0)
			break;
		block->next = (t_block*)((char*)block->ptr + block_size);
		block = block->next;			
	}
}

static t_zone	*initialize_zone(t_zone *zone, size_t size, const enum e_kind kind)
{
	zone->kind = kind;
	zone->next = NULL;
	zone->size = get_zone_size(size, kind);
	
	zone->blocks = (t_block*)((char*)zone + sizeof(t_zone));
	if (zone->kind == LARGE)
	{
		zone->blocks->free = true;
		zone->blocks->ptr = (void*)((char*)zone->blocks + sizeof(t_block));
		zone->blocks->next = NULL;
	}
	else if (zone->kind == SMALL)
		initialize_block(zone->blocks, SMALL_SIZE);
	else if (zone->kind == TINY)
		initialize_block(zone->blocks, TINY_SIZE);
	
	return (zone);
}

t_zone		*create_new_zone(size_t size, const enum e_kind kind)
{
	t_zone	*new;

	if (kind == TINY)
		new = MMAP(TINY_ZONE_SIZE);
	else if (kind == SMALL)
		new = MMAP(SMALL_ZONE_SIZE);
	else
		new = MMAP(LARGE_ZONE_SIZE(size));
		
	return (initialize_zone(new, size, kind));
}