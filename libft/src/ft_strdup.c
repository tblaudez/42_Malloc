/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:11:09 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 17:54:22 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *str;

    if (!(str = ft_strnew(ft_strlen(s1))))
        return NULL;
    ft_strcpy(str, s1);
    return (str);
}