/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_zone_size.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 12:44:32 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/08/27 10:47:19 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"

static size_t	align_page(size_t size)
{
	const size_t	page_size = getpagesize();

	return ((size % page_size) == 0 ? size : \
		((size / page_size) + 1) * page_size);
}

size_t			get_tiny_zone_size(void)
{
	const size_t block_size = TINY_MAX + sizeof(t_block);
	const size_t zone_size = (block_size * ALLOC_PER_ZONE) + sizeof(t_zone);

	return (align_page(zone_size));
}

size_t			get_small_zone_size(void)
{
	const size_t block_size = SMALL_MAX + sizeof(t_block);
	const size_t zone_size = (block_size * ALLOC_PER_ZONE) + sizeof(t_zone);

	return (align_page(zone_size));
}

size_t			get_large_zone_size(size_t alloc_size)
{
	return (align_page(alloc_size + sizeof(t_block) + sizeof(t_zone)));
}
