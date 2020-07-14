/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 10:48:57 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 12:11:21 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, const char *p1, const char *p2)
{
	size_t	gap;
	char	*ptr;
	char	*result;

	if (!ft_strcmp(p1, p2))
		return (ft_strdup(str));
	result = ft_strdup(str);
	while ((ptr = ft_strstr(result, p1)))
	{
		gap = ((size_t)ptr - (size_t)result);
		ptr = ft_strdup(ptr + ft_strlen(p1));
		result = ft_strnjoinfree(result, p2, gap, FREE_L);
		result = ft_strjoinfree(result, ptr, FREE_L | FREE_R);
	}
	return (result);
}
