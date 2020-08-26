/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 18:10:43 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/08/26 14:49:06 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static void	*copy_ptr_and_free(size_t size, t_block *block)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	ft_memcpy(new_ptr, block->ptr, ft_min(block->alloc_size, size));
	free(block->ptr);
	return (new_ptr);
}

void		*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	t_block	*block;

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
	{
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	if (size <= block->true_size)
	{
		block->alloc_size = size;
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	pthread_mutex_unlock(&g_mutex);
	return (copy_ptr_and_free(size, block));
}
