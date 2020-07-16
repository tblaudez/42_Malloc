/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blocks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 13:03:24 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/16 15:04:50 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block	*trim_block(t_block *block, size_t size)
{
	t_block	*tmp;

	tmp = block->next;
	block->next = (t_block*)((char*)block->ptr + size);
	block->next->ptr = (void*)((char*)block->next + sizeof(t_block));
	block->next->size = block->size - (size + sizeof(t_block));
	block->next->next = tmp;
	block->next->free = true;
	block->size = size;
	return (block);
}

static t_block	*find_free_block(t_block *block, size_t size)
{
	while (block)
	{
		if (block->free == true && block->size > (size + sizeof (t_block)))
			return (trim_block(block, size));
		block = block->next;
	}
	return (NULL);
}

t_block			*get_suitable_block(size_t size, const enum e_kind kind)
{
	t_zone	*zone;
	t_block	*block;

	if (kind == LARGE)
	{
		zone = create_new_zone(size, LARGE);
		zone->block->_large_real_size = size;
		return (zone->block);
	}
	if (g_malloc == NULL)
		g_malloc = create_new_zone(size, kind);
	zone = g_malloc;
	while (zone)
	{
		if (zone->kind == kind && (block = find_free_block(zone->block, size)))
			return (block);
		zone = zone->next;
	}
	zone = create_new_zone(size, kind);
	return (find_free_block(zone->block, size));
}

void			find_block_by_ptr(t_zone **zptr, t_block **bptr, void *ptr)
{
	t_zone	*zone;
	t_block	*block;

	zone = g_malloc;
	while (zone)
	{
		block = zone->block;
		while (block)
		{
			if (block->ptr == ptr)
			{
				(*zptr) = zone;
				(*bptr) = block;
				return ;
			}
			block = block->next;
		}
		zone = zone->next;
	}
	(*zptr) = NULL;
	(*bptr) = NULL;
}
