/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:31:21 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 18:29:59 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_udigitcount(size_t nbr, const int base)
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

static char	*ft_uitoabase(size_t value, const int base)
{
	char	*str;
	int		digits_count;

	digits_count = ft_udigitcount(value, base);
	str = ft_strnew(digits_count);

	while (digits_count--)
	{
		str[digits_count] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value /= base;
	}

	return (str);
}

static void	get_string(va_list ap, char **output, const char *formating)
{
	char	*value;
	char	*tmp;

	value = va_arg(ap, char*);
	tmp = (*output);
	(*output) = ft_strreplaceone(*output, formating, value);
	free(tmp);
}

static void	get_char(va_list ap, char **output, const char *formating)
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

static void	get_decimal(va_list ap, char **output, const char *formating)
{
	char	*value;
	char	*tmp;

	value = ft_itoabase(va_arg(ap, int), 10);
	tmp = (*output);
	(*output) = ft_strreplaceone(*output, formating, value);
	free(tmp);
}

static void	get_unsigned(va_list ap, char **output, const char *formating)
{
	char	*value;
	char	*tmp;

	value = ft_uitoabase(va_arg(ap, uint32_t), 10);
	tmp = (*output);
	(*output) = ft_strreplaceone(*output, formating, value);
	free(tmp);
}

static void	get_hexa(va_list ap, char **output, const char *formating)
{
	char	*value;
	char	*tmp;

	value = ft_strjoinfree("0x", ft_uitoabase(va_arg(ap, uint32_t), 16), FREE_R);
	tmp = (*output);
	(*output) = ft_strreplaceone(*output, formating, value);
	free(tmp);
}

static void	get_pointer(va_list ap, char **output, const char *formating)
{
	char	*value;
	char	*tmp;

	value = ft_strjoinfree("0x", ft_uitoabase(va_arg(ap, size_t), 16), FREE_R);
	tmp = (*output);
	(*output) = ft_strreplaceone(*output, formating, value);
	free(tmp);
}

static void	add_format(va_list ap, char *format, char **output)
{
	int			i;
	const char	*formating[6] = {"%s","%c","%d","%p","%x","%u"};
	void		(*const format_functions[6])(va_list ap, char **output, const char *formating) = {&get_string, &get_char, &get_decimal, &get_pointer, &get_hexa, &get_unsigned};

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(format, formating[i], 2))
		{
			format_functions[i](ap, output, formating[i]);
			return;
		}
		i++;
	}
}

static void	add_color(char *format, char **output)
{
	int			i;
	char		*tmp;
	const char	*color_code[14][2] = { {"{red}", "\x1b[31m"}, {"{green}", "\x1b[32m"}, {"{yellow}", "\x1b[33m"} \
	, {"{blue}", "\x1b[34m"}, {"{magenta}", "\x1b[35m"}, {"{cyan}", "\x1b[36m"}, {"{bold}", "\x1b[1m"} \
	, {"{dim}", "\x1b[2m"}, {"{underlined}", "\x1b[4m"}, {"{blink}", "\x1b[5m"}, {"{reverse}", "\x1b[7m"} \
	, {"{hidden}", "\x1b[8m"}, {"{end}", "\x1b[0m"}};

	i = 0;
	while (i < 14)
	{
		if (!ft_strncmp(format, color_code[i][0], ft_strlen(color_code[i][0])))
		{
			tmp = (*output);
			(*output) = ft_strreplaceone(*output, color_code[i][0], color_code[i][1]);
			free(tmp);
			return;
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