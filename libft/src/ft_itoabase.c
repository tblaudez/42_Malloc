/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoabase.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:01:52 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/23 11:47:12 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

char	*ft_itoabase(int value, const int base)
{
	char	*str;
	int		digits_count;
	char	is_negative;

	if (value == INT32_MIN)
		return (ft_strdup("-2147483648"));
	digits_count = ft_digitcount(value, base);
	str = ft_strnew(digits_count);
	if (value < 0)
	{
		is_negative = 1;
		value = -value;
	}
	while (digits_count)
	{
		digits_count--;
		str[digits_count] = (value % base) + \
			(value % base > 9 ? 'a' - 10 : '0');
		value /= base;
	}
	return (is_negative ? ft_strjoinfree("-", str, FREE_R) : str);
}
