/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:48:36 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 11:52:15 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoinfree(const char *s1, const char *s2, char flags)
{
    char    *new = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    ft_strcpy(new, s1);
    ft_strcpy(new + ft_strlen(s1), s2);
    
    if (flags & 1)
        free((void*)s1);
    if (flags & (1 << 1))
        free((void*)s2);
    return (new);
}