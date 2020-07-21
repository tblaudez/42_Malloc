/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_alloc_mem.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 18:46:53 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/21 13:27:15 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include "malloc.h"
#include "libft.h"


static t_zone	*get_next_similar_zone(t_kind kind)
{
	static t_zone	*zone = NULL;
	
	if (zone == NULL || zone->kind != kind)
		zone = g_malloc;
	else
		zone = zone->next;

	while (zone)
	{
		if (zone->kind == kind)
			return (zone);
		zone = zone->next;
	}
	return (NULL);
}

static void	show_zone(t_kind kind, const char *to_string, uint32_t *total_size)
{
	t_zone	*zone;
	t_block	*block;
	void	*block_end;

	if ((zone = get_next_similar_zone(kind)))
		ft_printf("%s: %p\n", to_string, zone);
	while (zone)
	{
		block = zone->block;
		while (block)
		{
			if (block->free == false)
			{
				block_end = (void*)((char*)block->ptr + block->alloc_size);
				ft_printf("%p - %p  : %u  bytes\n", block->ptr, block_end, block->alloc_size);
				(*total_size) += block->alloc_size;
			}
			block = block->next;
		}
		zone = get_next_similar_zone(kind);
	}
}

void		show_alloc_mem(void)
{
	uint32_t	total_size;

	total_size = 0;
	show_zone(TINY, "TINY", &total_size);
	show_zone(SMALL, "SMALL", &total_size);
	show_zone(LARGE, "LARGE", &total_size);
	ft_printf("Total : %u bytes\n", total_size);
}
