/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:25:52 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 18:34:18 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	ft_printf("s: %s\nc: %c\nd: %d\nu: %u\nx: %x\np: %p\n", "string", 'c', INT32_MIN, 0, 0, &ft_printf);
	
	return 0;
}
