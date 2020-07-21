/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_size.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 12:35:39 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/21 12:39:32 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "malloc.h"

bool	is_tiny(size_t alloc_size)
{
	return (alloc_size > 0 && alloc_size <= TINY_MAX);
}

bool	is_small(size_t alloc_size)
{
	return (alloc_size > TINY_MAX && alloc_size <= SMALL_MAX);
}

bool	is_large(size_t alloc_size)
{
	return (alloc_size > SMALL_MAX);
}
