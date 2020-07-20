/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_size.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 12:35:39 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/20 12:43:37 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "malloc.h"

bool	is_tiny(size_t alloc_size)
{
	return (alloc_size <= TINY_SIZE);
}

bool	is_small(size_t alloc_size)
{
	return (alloc_size > TINY_SIZE && alloc_size <= SMALL_SIZE);
}

bool	is_large(size_t alloc_size)
{
	return (alloc_size > SMALL_SIZE);
}
