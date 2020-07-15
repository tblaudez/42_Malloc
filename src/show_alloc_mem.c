/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_alloc_mem.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 18:46:53 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/15 14:06:10 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include "malloc.h"

static void	print_pointer_value(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		print_pointer_value(ptr / 16);
		print_pointer_value(ptr % 16);
	}
	else if (ptr >= 10)
		ft_putchar(ptr + ('a' - 10));
	else
		ft_putchar(ptr + '0');
}

static void	print_pointer(uintptr_t ptr)
{
	ft_putstr("0x");
	print_pointer_value(ptr);
}

static t_zone	*get_next_similar_zone(enum e_kind kind)
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

static void	print_zone_info(const char *to_string, t_zone *zone)
{
	ft_putstr(to_string);
	ft_putstr(": ");
	print_pointer((uintptr_t)zone);
	ft_putchar('\n');
}

static void	print_block_info(void *beg, void *end, size_t size)
{
	print_pointer((uintptr_t)beg);
	ft_putstr(" - ");
	print_pointer((uintptr_t)end);
	ft_putstr(" : ");
	ft_putnbr(size);
	ft_putstr(" bytes\n");
}

static void	show_zone(enum e_kind kind, const char *to_string, size_t *total_size)
{
	t_zone	*zone;
	t_block	*block;
	void	*block_end;

	if ((zone = get_next_similar_zone(kind)))
		print_zone_info(to_string, zone);
	while (zone)
	{
		block = zone->blocks;
		while (block)
		{
			if (block->free == false)
			{
				block_end = (zone->kind == LARGE ? (void*)((char*)zone + zone->size) : (void*)block->next);
				print_block_info(block->ptr, block, block->size);
				(*total_size) += block->size;
			}
			block = block->next;
		}
		zone = get_next_similar_zone(kind);
	}
}

void		show_alloc_mem(void)
{
	size_t	total_size;

	total_size = 0;
	show_zone(TINY, "TINY", &total_size);
	show_zone(SMALL, "SMALL", &total_size);
	show_zone(LARGE, "LARGE", &total_size);
	ft_putstr("Total : ");
	ft_putnbr(total_size);
	ft_putstr(" bytes\n");
}
