/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:07:52 by tblaudez          #+#    #+#             */
/*   Updated: 2018/10/11 15:20:46 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int		ft_unbrdig(uintmax_t nbr, int base)
{
	int	i;

	i = 1;
	while (nbr /= base)
		i++;
	return (i);
}

char	*ft_uitoabase(uintmax_t nbr, int base)
{
	char	*str;
	int		i;

	i = ft_unbrdig(nbr, base);
	str = ft_strnew(i);
	while (i-- > 0)
	{
		str[i] = (nbr % base) + (nbr % base > 9 ? 'a' - 10 : '0');
		nbr /= base;
	}
	return (str);
}
