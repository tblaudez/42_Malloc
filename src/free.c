/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 17:46:56 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 14:44:18 by tblaudez      ########   odam.nl         */
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
		delete_zone(zone);
		munmap(zone, zone->size);
	}
}
