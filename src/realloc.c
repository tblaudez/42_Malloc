/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 18:10:43 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/21 14:21:23 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

void	*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	t_block	*block;
	void	*new_ptr;

	find_block_by_ptr(&zone, &block, ptr);
	if (ptr == NULL || block == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (malloc(1));
	}
	if (size <= block->true_size)
	{
		block->alloc_size = size;
		return (ptr);
	}
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, block->alloc_size);
	free(ptr);
	return (new_ptr);
}
