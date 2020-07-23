/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 14:35:47 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 11:44:23 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

int		ft_udigitcount(uintmax_t nbr, int base)
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

char	*ft_uitoabase(uintmax_t value, int base)
{
	char	*str;
	int		digits_count;

	digits_count = ft_udigitcount(value, base);
	str = ft_strnew(digits_count);
	while (digits_count)
	{
		digits_count--;
		str[digits_count] = (value % base) + \
			(value % base > 9 ? 'a' - 10 : '0');
		value /= base;
	}
	return (str);
}
