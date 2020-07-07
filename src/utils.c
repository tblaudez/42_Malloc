/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:47:56 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 18:35:43 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	delete_zone(t_zone *zone)
{
	t_zone *tmp;

	if (zone == g_malloc)
	{
		g_malloc = zone->next;
		return;
	}	

	tmp = g_malloc;
	while (tmp->next != zone)
		tmp = tmp->next;
	
	tmp->next = zone->next;
}

void	append_new_zone(t_zone *new)
{
	t_zone	*zone;

	zone = g_malloc;
	while (zone->next)
		zone = zone->next;
	
	zone->next = new;
}

t_block	*find_free_block(t_block *block)
{
	while (block)
	{
		if (block->free == true)
			return block;
		block = block->next;
	}

	return NULL;
}

size_t	get_zone_size(size_t size, const enum e_kind kind)
{
	if (kind == TINY)
		return TINY_ZONE_SIZE;
	else if (kind == SMALL)
		return SMALL_ZONE_SIZE;
	else
		return LARGE_ZONE_SIZE(size);
}

t_block	*get_suitable_block(size_t size, const enum e_kind kind)
{
	t_zone	*zone;
	t_block	*block;

	if (g_malloc == NULL)
	{
		g_malloc = create_new_zone(size, kind);
		return g_malloc->blocks;
	}

	zone = g_malloc;
	while (zone)
	{
		if (zone->kind == kind && (block = find_free_block(zone->blocks)))
			return block;
		zone = zone->next;	
	}

	zone = create_new_zone(size, kind);
	append_new_zone(zone);

	return zone->blocks;
}

void	find_block_by_ptr(t_zone **zptr, t_block **bptr, void *ptr)
{
	t_zone	*zone;
	t_block	*block;

	zone = g_malloc;
	while (zone)
	{
		block = zone->blocks;
		while (block)
		{
			if (block->ptr == ptr)
			{
				*zptr = zone;
				*bptr = block;
				return;
			}
			block = block->next;
		}
		zone = zone->next;
	}
	
	*zptr = NULL;
	*bptr = NULL;
}