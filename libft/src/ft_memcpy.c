/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 18:19:26 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 12:05:59 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy `n` bytes from `src` to `dst`
** @param: (void *dst) - The destination memory area
** @param: (const void *src) - The source memory area
** @return: (void*) - The original value of `dst`
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_dup;
	char		*dst_dup;

	src_dup = (char*)src;
	dst_dup = (char*)dst;
	while (n--)
	{
		*dst_dup = *src_dup;
		dst_dup++;
		src_dup++;
	}
	return (dst);
}
