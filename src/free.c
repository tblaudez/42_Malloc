/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 17:46:56 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/15 14:25:48 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

void	free(void *ptr)
{
	t_zone	*zone;
	t_block	*block;

	find_block_by_ptr(&zone, &block, ptr);
	if (block == NULL)
		return ;
	block->free = true;
	if (zone->kind == LARGE)
	{
		remove_zone_from_list(zone);
		munmap(zone, zone->size);
	}
}
