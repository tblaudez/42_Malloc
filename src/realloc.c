/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:10:43 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 18:37:35 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	t_zone *zone;
	t_block	*block;
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_malloc(size));
	if (size == 0)
	{
		ft_free(ptr);
		return (ft_malloc(1));
	}
	
	find_block_by_ptr(&zone, &block, ptr);
	if ((zone->kind == TINY && size <= TINY_SIZE) \
	|| (zone->kind == SMALL && size <= SMALL_SIZE) \
	|| (zone->kind == LARGE && size <= (zone->size - (sizeof(t_block) + sizeof(t_zone)))))
		return ptr;
	
	new_ptr = ft_malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	ft_free(ptr);
	return (new_ptr);
}