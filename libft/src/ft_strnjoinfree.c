/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:00:57 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 17:57:11 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnjoinfree(const char *s1, const char *s2, size_t size, char flags)
{
    char   	*new;
	
	size = MIN(ft_strlen(s1), size);
	new = ft_strnew(size + ft_strlen(s2));
	
    ft_strncpy(new, s1, size);
    ft_strcpy(new + size, s2);
    
    if (flags & 1)
        free((void*)s1);
    if (flags & (1 << 1))
        free((void*)s2);
    return (new);
}