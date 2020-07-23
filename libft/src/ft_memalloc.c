/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 17:55:02 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 11:16:43 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocate `size` 0-initialized bytes of memory
** @param: (size_t size) - The size of the memory that needs to be allocated
** @return: (void*) - The allocated memory or *NULL* if the allocation failed
*/

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
