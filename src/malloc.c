/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 12:37:13 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/16 11:01:28 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "malloc.h"

t_zone		*g_malloc = NULL;

void		*malloc(size_t size)
{
	t_block	*block;

	if (is_tiny(size))
		block = get_suitable_block(size, TINY);
	else if (is_small(size))
		block = get_suitable_block(size, SMALL);
	else if (is_large(size))
		block = get_suitable_block(size, LARGE);
	else
		return ((block = NULL));
	block->free = false;
	block->size = size;
	return (block->ptr);
}
