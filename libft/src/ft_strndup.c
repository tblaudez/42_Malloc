/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:34:36 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 17:56:15 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strndup(const char *s1, size_t size)
{
	char    *str;

	if (!(str = ft_strnew(size)))
        return NULL;
	ft_strncpy(str, s1, size);
	return (str);
}