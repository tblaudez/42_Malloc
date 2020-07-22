/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_alloc_mem_hex.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 14:10:03 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/22 14:59:47 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static void		hexdump_memory(void *addr, uint32_t size)
{
	const uint8_t	*bytes = (const uint8_t*)addr;
	uint32_t		i;

	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			if (i != 0)
				ft_putchar('\n');
			ft_printf("%P ", bytes + i);;
		}
		ft_printf("%X ", *(bytes + i));
		i++;
	}
	ft_putchar('\n');
}

static void	show_zone_hex(t_kind kind, const char *to_string, uint32_t *total_size)
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
				hexdump_memory(block->ptr, block->alloc_size);
				(*total_size) += block->alloc_size;
			}
			block = block->next;
		}
		zone = get_next_similar_zone(kind);
	}
}

void		show_alloc_mem_hex(void)
{
	uint32_t	total_size;

	total_size = 0;
	show_zone_hex(TINY, "TINY", &total_size);
	show_zone_hex(SMALL, "SMALL", &total_size);
	show_zone_hex(LARGE, "LARGE", &total_size);
	ft_printf("Total : %u bytes\n", total_size);
}
