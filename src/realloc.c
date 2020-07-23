/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 18:10:43 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 12:31:42 by tblaudez      ########   odam.nl         */
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
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (malloc(1));
	}
	pthread_mutex_lock(&g_mutex);
	find_block_by_ptr(&zone, &block, ptr);
	if (block == NULL)
		return (NULL);
	if (size <= block->true_size)
	{
		block->alloc_size = size;
		return (ptr);
	}
	pthread_mutex_unlock(&g_mutex);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, ft_min(block->alloc_size, size));
	free(ptr);
	return (new_ptr);
}
