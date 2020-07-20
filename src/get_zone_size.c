/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_zone_size.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 12:44:32 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/20 13:20:14 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"

static size_t	align_page(size_t size)
{
	return (((size / getpagesize()) + 1) * getpagesize());
}

size_t			get_tiny_zone_size(size_t alloc_size)
{
	(void)alloc_size;
	return (align_page(((TINY_SIZE + sizeof(t_block))\
	* ALLOCATION_PER_ZONE) + sizeof(t_zone)));
}

size_t			get_small_zone_size(size_t alloc_size)
{
	(void)alloc_size;
	return (align_page(((SMALL_SIZE + sizeof(t_block))\
	* ALLOCATION_PER_ZONE) + sizeof(t_zone)));
}

size_t			get_large_zone_size(size_t alloc_size)
{
	return (align_page(alloc_size + sizeof(t_block) + sizeof(t_zone)));
}
