/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:32:54 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 11:51:34 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free the memory of a link and every successor of that link using `del()`
** and set the pointer to that link to NULL
** @param: (t_list **alst) - The address of a pointer to the first link of a list that needs to be freed
** @param: (void (*del)(void*, size_t)) - The address of a function to apply to each link of a list
*/

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{	
	if ((*alst)->next)
		ft_lstdel(&((*alst)->next), del);
	
	ft_lstdelone(alst, del);
}