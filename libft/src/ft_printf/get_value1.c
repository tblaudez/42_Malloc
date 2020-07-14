/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_value1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 11:41:32 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 12:15:43 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

void	get_string(va_list ap, char **output, const char *formating)
{
	char	*value;
	char	*tmp;

	value = va_arg(ap, char*);
	tmp = (*output);
	(*output) = ft_strreplaceone(*output, formating, value);
	free(tmp);
}

void	get_char(va_list ap, char **output, const char *formating)
{
	char	value;
	char	*tmp;
	char	*tmp2;

	value = (char)va_arg(ap, int);
	tmp2 = ft_strndup(&value, 1);
	tmp = (*output);
	(*output) = ft_strreplaceone(*output, formating, tmp2);
	free(tmp);
	free(tmp2);
}

void	get_decimal(va_list ap, char **output, const char *formating)
{
	char	*value;
	char	*tmp;

	value = ft_itoabase(va_arg(ap, int), 10);
	tmp = (*output);
	(*output) = ft_strreplaceone(*output, formating, value);
	free(tmp);
}
