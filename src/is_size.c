/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_size.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 12:35:39 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 12:57:45 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "malloc.h"

bool	is_tiny(size_t size)
{
	return (size <= TINY_SIZE);
}

bool	is_small(size_t size)
{
	return (size > TINY_SIZE && size <= SMALL_SIZE);
}

bool	is_large(size_t size)
{
	return (size > SMALL_SIZE);
}
