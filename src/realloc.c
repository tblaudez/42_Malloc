/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 18:10:43 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/22 14:07:53 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

void	*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	t_block	*block;
	void	*new_ptr;

	if (ptr == NULL)
		return(malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (malloc(1));
	}
	find_block_by_ptr(&zone, &block, ptr);
	if (block == NULL)
		return (NULL);
	if (size <= block->true_size)
	{
		block->alloc_size = size;
		return (ptr);
	}
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, ft_min(block->alloc_size, size));
	free(ptr);
	return (new_ptr);
}
