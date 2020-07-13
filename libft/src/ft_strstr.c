/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:10:10 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 12:13:27 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	size_t	len;

	if (!(*needle))
		return ((char*)haystack);
	len = ft_strlen(needle);
	i = 0;
	while (haystack[i])
	{
		if (!ft_strncmp(haystack + i, needle, len))
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}