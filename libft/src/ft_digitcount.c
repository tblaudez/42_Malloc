/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:05:28 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 18:08:57 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digitcount(int nbr, const int base)
{
	int	digits;

	if (nbr == 0)
		return (1);
	
	digits = 0;
	while (nbr)
	{
		nbr /= base;
		digits++;
	}

	return (digits);
}