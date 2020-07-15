/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_value2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 11:42:44 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/15 11:25:00 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libft.h"

static int	ft_udigitcount(uintmax_t nbr, int base)
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

static char	*ft_uitoabase(uintmax_t value, int base)
{
	char	*str;
	int		digits_count;

	digits_count = ft_udigitcount(value, base);
	str = ft_strnew(digits_count);
	while (digits_count--)
	{
		str[digits_count] = (value % base)\
		+ (value % base > 9 ? 'a' - 10 : '0');
		value /= base;
	}
	return (str);
}

void		get_pointer(va_list ap, char **output, const char *format_code)
{
	char	*value;
	char	*tmp;

	value = ft_strjoinfree("0x", ft_uitoabase(va_arg(ap, uintptr_t), 16), FREE_R);
	tmp = ft_strreplaceone(*output, format_code, value);
	free(*output);
	free(value);
	(*output) = tmp;
}

void		get_unsigned(va_list ap, char **output, const char *format_code)
{
	char	*value;
	char	*tmp;

	value = ft_uitoabase(va_arg(ap, uint32_t), 10);
	tmp = ft_strreplaceone(*output, format_code, value);
	free(*output);
	free(value);
	(*output) = tmp;
}

void		get_hexa(va_list ap, char **output, const char *format_code)
{
	char	*value;
	char	*tmp;

	value = ft_strjoinfree("0x"\
	, ft_uitoabase(va_arg(ap, uint32_t), 16), FREE_R);
	tmp = ft_strreplaceone(*output, format_code, value);
	free(*output);
	free(value);
	(*output) = tmp;
}
