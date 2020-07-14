/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 17:56:56 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 12:06:21 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Write `n` bytes of value `c` (to unsigned char) to memory area `s`
** @param: (void *s) - The memory area to be set
** @param: (int c) - The value the bytes will be set to
** @param: (size_t n) - The number of bytes to set
** @return: (void*) - The original value of `s`
*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_dup;

	s_dup = (char*)s;
	while (n--)
	{
		*s_dup = (unsigned char)c;
		s_dup++;
	}
	return (s);
}
