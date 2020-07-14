/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 18:10:43 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 14:45:35 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	t_block	*block;
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (malloc(1));
	}
	find_block_by_ptr(&zone, &block, ptr);
	if ((zone->kind == TINY && size <= TINY_SIZE)\
	|| (zone->kind == SMALL && size <= SMALL_SIZE)\
	|| (zone->kind == LARGE && size <=\
	(zone->size - (sizeof(t_block) + sizeof(t_zone)))))
		return (ptr);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
