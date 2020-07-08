/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:31:21 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/08 14:41:09 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_format(char *format)
{
	return;
}

static void	add_color(char *format)
{
	int			i;
	const char	*color_code[14][2] = { {"red", "\x1b[31m"}, {"green", "\x1b[32m"}, {"yellow", "\x1b[33m"} \
	, {"blue", "\x1b[34m"}, {"magenta", "\x1b[35m"}, {"cyan", "\x1b[36m"}, {"bold", "\x1b[1m"} \
	, {"dim", "\x1b[2m"}, {"underlined", "\x1b[4m"}, {"blink", "\x1b[5m"}, {"reverse", "\x1b[7m"} \
	, {"hidden", "\x1b[8m"}, {"end", "\x1b[0m"}};

	i = 14;
	while (i--)
	{
		ft_putendl(color_code[i][0]);
	}


}

void		ft_printf(char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '{')
			add_color(format + 1);
		else if (*format == '%')
			add_format(format + 1);
		format++;
	}
	ft_putstr(format);
	va_end(ap);
}

int main(int argc, char const *argv[])
{
	ft_printf("Hello {red}%s{end}\n", "there");
	return 0;
}
