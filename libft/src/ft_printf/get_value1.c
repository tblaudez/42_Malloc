/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_value1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 11:41:32 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/15 11:28:00 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

void	get_string(va_list ap, char **output, const char *format_code)
{
	char	*value;
	char	*tmp;

	value = va_arg(ap, char*);
	tmp = ft_strreplaceone(*output, format_code, value);
	free(*output);
	(*output) = tmp;
}

void	get_char(va_list ap, char **output, const char *format_code)
{
	char	*value;
	char	*tmp;

	value = ft_strnew(1);
	(*value) = (char)va_arg(ap, int);
	tmp = ft_strreplaceone(*output, format_code, value);
	free(*output);
	free(value);
	(*output) = tmp;
}

void	get_decimal(va_list ap, char **output, const char *format_code)
{
	char	*value;
	char	*tmp;

	value = ft_itoabase(va_arg(ap, int), 10);
	tmp = ft_strreplaceone(*output, format_code, value);
	free(*output);
	free(value);
	(*output) = tmp;
}
