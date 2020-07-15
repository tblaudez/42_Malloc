/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zones.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 14:42:01 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/15 14:45:23 by tblaudez      ########   odam.nl         */
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

static t_zone	*initialize_zone(t_zone *zone, size_t size\
, const enum e_kind kind)
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

#include <unistd.h>
t_zone			*create_new_zone(size_t size, const enum e_kind kind)
{
	t_zone	*new;
	
	
	
	// ft_putstr("MMAP - ");
	// if (kind == TINY)
	// {
	// 	ft_putstr("TINY - ");
	// 	ft_putnbr(get_tiny_zone_size() / getpagesize());
	// 	ft_putstr(" pages - ");
	// 	ft_putnbr(size);
	// 	ft_putendl(" bytes");
	// }
	// else if (kind == SMALL)
	// {
	// 	ft_putstr("SMALL - ");
	// 	ft_putnbr(get_small_zone_size() / getpagesize());
	// 	ft_putstr(" pages - ");
	// 	ft_putnbr(size);
	// 	ft_putendl(" bytes");
	// }
	// else
	// 	{
	// 	ft_putstr("LARGE - ");
	// 	ft_putnbr(get_large_zone_size(size) / getpagesize());
	// 	ft_putstr(" pages - ");
	// 	ft_putnbr(size);
	// 	ft_putendl(" bytes");
	// }
	
	if (kind == TINY)
		new = mmap(NULL, get_tiny_zone_size(), PROT_READ | PROT_WRITE\
		, MAP_ANON | MAP_PRIVATE, -1, 0);
	else if (kind == SMALL)
		new = mmap(NULL, get_small_zone_size(), PROT_READ | PROT_WRITE\
		, MAP_ANON | MAP_PRIVATE, -1, 0);
	else
		new = mmap(NULL, get_large_zone_size(size), PROT_READ | PROT_WRITE\
		, MAP_ANON | MAP_PRIVATE, -1, 0);
	return (initialize_zone(new, size, kind));
}

void			remove_zone_from_list(t_zone *zone)
{
	t_zone *tmp;

	if (zone == g_malloc)
	{
		g_malloc = zone->next;
		return ;
	}
	tmp = g_malloc;
	while (tmp->next != zone)
		tmp = tmp->next;
	tmp->next = zone->next;
}

void			append_new_zone(t_zone *new)
{
	t_zone	*zone;

	zone = g_malloc;
	while (zone->next)
		zone = zone->next;
	zone->next = new;
}
