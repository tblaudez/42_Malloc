/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 10:17:53 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 12:27:40 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

void	*calloc(size_t count, size_t size)
{
	const size_t	alloc_size = count * size;
	void			*ptr;

	ptr = malloc(alloc_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, alloc_size);
	return (ptr);
}
