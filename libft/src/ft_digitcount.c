/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digitcount.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 11:57:24 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 12:02:02 by tblaudez      ########   odam.nl         */
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
