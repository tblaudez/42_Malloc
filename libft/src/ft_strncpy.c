/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:40:24 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 11:37:00 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strncpy(char *dst, const char *src, size_t len)
{
    int i;

    i = 0;
    while (src[i] && len)
    {
        dst[i] = src[i];
        i++;
        len--;
    }
    while (len--)
        dst[i] = '\0';
    return (dst);
}