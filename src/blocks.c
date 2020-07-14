/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blocks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 13:03:24 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 13:58:29 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block	*find_free_block(t_block *block)
{
	while (block)
	{
		if (block->free == true)
			return (block);
		block = block->next;
	}
	return (NULL);
}

t_block			*get_suitable_block(size_t size, const enum e_kind kind)
{
	t_zone	*zone;
	t_block	*block;

	if (g_malloc == NULL)
	{
		g_malloc = create_new_zone(size, kind);
		return (g_malloc->blocks);
	}
	zone = g_malloc;
	while (zone)
	{
		if (zone->kind == kind && (block = find_free_block(zone->blocks)))
			return (block);
		zone = zone->next;
	}
	zone = create_new_zone(size, kind);
	append_new_zone(zone);
	return (zone->blocks);
}

void			find_block_by_ptr(t_zone **zptr, t_block **bptr, void *ptr)
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
				return ;
			}
			block = block->next;
		}
		zone = zone->next;
	}
	*zptr = NULL;
	*bptr = NULL;
}

void			initialize_block(t_block *block, size_t block_size)
{
	int	i;

	i = ALLOCATION_PER_ZONE;
	while (i--)
	{
		block->free = true;
		block->ptr = (void*)((char*)block + sizeof(t_block));
		if (i == 0)
			break ;
		block->next = (t_block*)((char*)block->ptr + block_size);
		block = block->next;
	}
}
