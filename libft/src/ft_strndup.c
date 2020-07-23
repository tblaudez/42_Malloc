/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 10:34:36 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 11:21:06 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*str;

	str = ft_strnew(size);
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, size);
	return (str);
}
