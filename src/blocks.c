/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blocks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 13:03:24 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/08/27 10:48:03 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static size_t	align_size(size_t size)
{
	return (size % 16 == 0 ? size : ((size / 16) + 1) * 16);
}

static t_block	*trim_block(t_block *block, size_t alloc_size)
{
	const size_t	true_size = align_size(alloc_size);
	t_block			*tmp;

	tmp = block->next;
	block->next = (t_block*)((char*)block->ptr + true_size);
	block->next->ptr = (void*)((char*)block->next + sizeof(t_block));
	block->next->true_size = block->true_size - (true_size + sizeof(t_block));
	block->next->next = tmp;
	block->next->alloc_size = 0;
	block->next->free = true;
	block->true_size = true_size;
	block->alloc_size = alloc_size;
	return (block);
}

static t_block	*find_free_block(t_zone *zone, size_t alloc_size)
{
	t_block	*block;

	block = zone->block;
	while (block)
	{
		if (block->free == true && alloc_size < block->true_size)
		{
			if (zone->kind == LARGE || (block->true_size - alloc_size) < 32)
			{
				block->alloc_size = alloc_size;
				return (block);
			}
			return (trim_block(block, alloc_size));
		}
		block = block->next;
	}
	return (NULL);
}

t_block			*get_suitable_block(size_t alloc_size, const t_kind kind)
{
	t_zone	*zone;
	t_block	*block;

	if (g_malloc == NULL)
		g_malloc = create_new_zone(alloc_size, kind);
	zone = g_malloc;
	while (zone)
	{
		if (zone->kind == kind)
		{
			block = find_free_block(zone, alloc_size);
			if (block != NULL)
				return (block);
		}
		zone = zone->next;
	}
	zone = create_new_zone(alloc_size, kind);
	return (find_free_block(zone, alloc_size));
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
