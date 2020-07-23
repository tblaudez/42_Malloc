/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 17:46:56 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 12:51:23 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdlib.h>
#include "malloc.h"
#include "libft.h"

static bool	zone_is_empty(t_zone *zone)
{
	t_block	*block;

	block = zone->block;
	while (block)
	{
		if (block->free == false)
			return (false);
		block = block->next;
	}
	return (true);
}

static int	count_empty_zones(t_kind kind)
{
	t_zone	*zone;
	int		count;

	zone = g_malloc;
	count = 0;
	while (zone)
	{
		if (zone->kind == kind && zone_is_empty(zone))
			count++;
		zone = zone->next;
	}
	return (count);
}

static void	remove_zone_from_list(t_zone *to_delete)
{
	t_zone *zone;

	if (to_delete == g_malloc)
	{
		g_malloc = to_delete->next;
		return ;
	}
	zone = g_malloc;
	while (zone->next != to_delete)
		zone = zone->next;
	zone->next = zone->next->next;
}

static void	start_defragmentation(t_zone *zone)
{
	t_block	*block;
	
	block = zone->block;
	while (block)
	{
		if (block->free == true && block->next && block->next->free == true)
		{
			block->true_size += (block->next->true_size + sizeof(t_block));
			block->next = block->next->next;
			continue ;
		}
		block = block->next;
	}
}

void		free(void *ptr)
{
	t_zone	*zone;
	t_block	*block;

	if (ptr == NULL)
		return ;
	pthread_mutex_lock(&g_mutex);
	find_block_by_ptr(&zone, &block, ptr);
	if (block == NULL)
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	block->free = true;
	block->alloc_size = 0;
	if (zone->kind == LARGE || (zone_is_empty(zone) &&\
			count_empty_zones(zone->kind) > 1))
	{
		remove_zone_from_list(zone);
		if (munmap(zone, zone->size) == -1)
		{
			ft_putendl("free() - munmap error");
			exit(1);
		}
	}
	else
		start_defragmentation(zone);
	pthread_mutex_unlock(&g_mutex);
}
