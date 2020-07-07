/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:49:36 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 11:51:03 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Apply `f()` to each link of a list
** @param: (t_list *link) - A pointer to the first link of a list
** @param: (void (*f)(t_list *elem)) - The address of the function to apply to each link of the list
*/

void	ft_lstiter(t_list *link, void (*f)(t_list *elem))
{
	if (link == NULL)
		return;
	f(link);
	ft_lstiter(link->next, f);
}