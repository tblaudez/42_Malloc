/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 11:47:56 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/07/20 13:58:45 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>

int	main(void)
{
	void	*addr;

	addr = malloc(1487);
	//show_alloc_mem();
	return 0;
}
