/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 19:31:21 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/14 12:15:05 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

static void	add_format(va_list ap, char *format, char **output)
{
	int			i;
	const char	*formating[6] = {"%s", "%c", "%d", "%p", "%x", "%u"};
	void		(*const format_functions[6])(va_list ap, char **output\
	, const char *formating) = {&get_string, &get_char, &get_decimal,\
	&get_pointer, &get_hexa, &get_unsigned};

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(format, formating[i], 2))
		{
			format_functions[i](ap, output, formating[i]);
			return ;
		}
		i++;
	}
}

static void	add_color(char *format, char **output)
{
	int			i;
	char		*tmp;
	const char	*color_code[14][2] = { {"{red}", "\x1b[31m"}\
	, {"{green}", "\x1b[32m"}, {"{yellow}", "\x1b[33m"}, {"{blue}"\
	, "\x1b[34m"}, {"{magenta}", "\x1b[35m"}, {"{cyan}", "\x1b[36m"}\
	, {"{bold}", "\x1b[1m"}, {"{dim}", "\x1b[2m"}, {"{underlined}"\
	, "\x1b[4m"}, {"{blink}", "\x1b[5m"}, {"{reverse}", "\x1b[7m"}\
	, {"{hidden}", "\x1b[8m"}, {"{end}", "\x1b[0m"}};

	i = 0;
	while (i < 14)
	{
		if (!ft_strncmp(format, color_code[i][0], ft_strlen(color_code[i][0])))
		{
			tmp = (*output);
			(*output) = ft_strreplaceone(*output, color_code[i][0]\
			, color_code[i][1]);
			free(tmp);
			return ;
		}
		i++;
	}
}

void		ft_printf(char *format, ...)
{
	va_list ap;
	char	*output;

	output = ft_strdup(format);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '{')
			add_color(format, &output);
		else if (*format == '%')
			add_format(ap, format, &output);
		format++;
	}
	ft_putstr(output);
	va_end(ap);
}
