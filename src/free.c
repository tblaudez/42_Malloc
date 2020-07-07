/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:46:56 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 18:23:53 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_free(void *ptr)
{
	t_zone	*zone;
	t_block	*block;

	find_block_by_ptr(&zone, &block, ptr);
	if (block == NULL)
		return;
		
	block->free = true;
	if (zone->kind == LARGE)
	{
		delete_zone(zone);
		munmap(zone, zone->size);
	}
}