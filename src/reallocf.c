/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reallocf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 15:03:06 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 15:05:25 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*reallocf(void *ptr, size_t size)
{
	void	*ptr2;

	ptr2 = realloc(ptr, size);
	if (ptr2 == NULL)
		free(ptr);
	return (ptr2);
}
