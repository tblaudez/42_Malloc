/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 18:53:15 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 11:18:10 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	if (s == NULL || *s == '\0')
		return (0);
	return (1 + ft_strlen(s + 1));
}
