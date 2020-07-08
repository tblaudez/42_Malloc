/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:48:36 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/08 14:31:17 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoinfree(char *s1, char *s2)
{
    char    *new = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    ft_strcpy(new, s1);
    ft_strcpy(new + ft_strlen(s1), s2);
    free(s1);
    free(s2);
    return (new);
}