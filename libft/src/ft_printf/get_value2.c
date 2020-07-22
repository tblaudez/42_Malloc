/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_value2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 11:42:44 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/22 14:53:53 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "libft.h"

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

void		get_pure_pointer(va_list ap, char **output, const char *format_code)
{
	char	*value;
	char	*tmp;

	value = ft_uitoabase(va_arg(ap, uintptr_t), 16);
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

void		get_pure_hexa(va_list ap, char **output, const char *format_code)
{
	uint32_t	value;
	char		*str_value;
	char		*tmp;

	value = va_arg(ap, uint32_t);
	str_value = ft_uitoabase(value, 16);
	if (value < 16)
		str_value = ft_strjoinfree("0", str_value, FREE_R);
	tmp = ft_strreplaceone(*output, format_code, str_value);
	free(*output);
	free(str_value);
	(*output) = tmp;
}
