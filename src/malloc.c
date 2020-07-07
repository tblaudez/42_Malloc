/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:37:13 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 17:14:12 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zone		*g_malloc = NULL;

void		*ft_malloc(size_t size)
{
	t_block	*block;

	if (ISTINY(size))
		block = get_suitable_block(size, TINY);
	else if (ISSMALL(size))
		block = get_suitable_block(size, SMALL);
	else if (ISLARGE(size))
		block = get_suitable_block(size, LARGE);
	else
		return ((block = NULL));
	
	block->free = false;
	return (block->ptr);
}