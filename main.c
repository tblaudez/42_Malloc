/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 11:47:56 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/16 14:47:25 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>

int	main(void)
{
	void	*addr;
	size_t	size;

	for (int i=0; i < 100; i++)
	{
		size = arc4random_uniform(10000);
		addr = malloc(size);
		if (i % 3 == 0)
			free(addr);
	}
	show_alloc_mem();
	return 0;
}
