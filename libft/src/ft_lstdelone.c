/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:27:33 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 11:51:18 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free a the memory of a link using `del()` then free the link itself
** Finally, set the pointer to the link that was freed to NULL
** @param: (t_list **alst) - The address of a pointer to the link that needs to be freed
** @param: (void (*del)(void*, size_t)) - The address of a function to apply to the link
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}