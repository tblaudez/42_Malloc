/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 19:31:21 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/22 14:43:26 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

static void	add_format(va_list ap, char **format, char **output)
{
	int			i;
	const char	*format_codes[8] = {"%s", "%c", "%d", "%p", "%P", "%x", "%X", "%u"};
	void		(*const format_functions[8])(va_list ap, char **output\
	, const char *format_codes) = {&get_string, &get_char, &get_decimal,\
	&get_pointer, &get_pure_pointer, &get_hexa, &get_pure_hexa, &get_unsigned};

	i = 0;
	while (i < 8)
	{
		if (!ft_strncmp(*format, format_codes[i], ft_strlen(format_codes[i])))
		{
			format_functions[i](ap, output, format_codes[i]);
			(*format) += ft_strlen(format_codes[i]);
			return ;
		}
		i++;
	}
}

static void	add_color(char **format, char **output)
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
		if (!ft_strncmp(*format, color_code[i][0], ft_strlen(color_code[i][0])))
		{
			tmp = ft_strreplaceone(*output, color_code[i][0], color_code[i][1]);
			free(*output);
			(*output) = tmp;
			(*format) += ft_strlen(color_code[i][0]);
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
			add_color(&format, &output);
		else if (*format == '%')
			add_format(ap, &format, &output);
		else
			format++;
	}
	ft_putstr(output);
	free(output);
	va_end(ap);
}
