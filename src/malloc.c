/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 12:37:13 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/20 13:57:16 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "malloc.h"

t_zone		*g_malloc = NULL;

static enum e_kind	get_kind(size_t alloc_size)
{
	if (is_tiny(alloc_size))
		return (TINY);
	else if (is_small(alloc_size))
		return (SMALL);
	else if (is_large(alloc_size))
		return (LARGE);
	return (INVALID);
}
#include <stdint.h>
void				*malloc(size_t size)
{
	const enum e_kind	kind = get_kind(size);
	t_block				*block;

	if (kind == INVALID)
		return (NULL);
	block = get_suitable_block(size, kind);
	block->free = false;
	return (block->ptr);
}
