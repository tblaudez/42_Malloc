/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:05:22 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 19:17:51 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	void	*ptr;

	for (int i=0; i<10000; i++)
	{
		uint32_t size = arc4random_uniform(2000);
		ptr = ft_malloc(size);
		if (i % 12 == 0)
			ptr = ft_realloc(ptr, size*2);
		if (i % 16 == 0)
			ft_free(ptr);
	}

	return 0;
}