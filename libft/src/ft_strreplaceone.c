/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strreplaceone.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 14:38:20 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 11:30:02 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strreplaceone(char *src, const char *p1, const char *p2)
{
	size_t			gap;
	char			*tmp;
	char			*dst;
	const size_t	p1_size = ft_strlen(p1);

	dst = ft_strdup(src);
	if (!ft_strcmp(p1, p2))
		return (dst);
	tmp = ft_strstr(dst, p1);
	if (tmp)
	{
		gap = ((uintptr_t)tmp - (uintptr_t)dst);
		tmp = ft_strdup(tmp + p1_size);
		dst = ft_strnjoinfree(dst, p2, gap, FREE_L);
		dst = ft_strjoinfree(dst, tmp, FREE_L | FREE_R);
		tmp = ft_strstr(dst, p1);
	}
	return (dst);
}
