/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 10:02:35 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 13:16:44 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int i;

	i = 0;
	len--;
	while (s1[i] && s2[i] && s1[i] == s2[i] && len)
	{
		i++;
		len--;
	}
	return (s1[i] - s2[i]);
}
