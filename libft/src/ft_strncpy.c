/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:40:24 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/08 13:44:00 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strncpy(char *dst, char *src, size_t len)
{
    while (*src && len)
    {
        *dst = *src;
        dst++;
        src++;
        len--;
    }
    while (len--)
        *dst = '\0';
    return (dst);
}