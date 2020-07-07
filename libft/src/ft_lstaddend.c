/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:40:44 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 11:51:49 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add the element `new` at the end of a list
** @param: (t_list **alst) - The address of a pointer to a link
** @param: (t_list *new) - The link to add at the end of the list
*/

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*link;

	link = *alst;
	while (link->next)
		link = link->next;
	link->next = new;
}