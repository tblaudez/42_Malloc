/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:51:26 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 11:50:38 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a newly allocated link then **copy** `content` and `content_size` as it's attributes
** If `content` is NULL, the link's attributes are set to *NULL* and *0*
** The link's `->next` attribute is initialized to NULL
** @param: (void const *content) - The content to put in the new link
** @param: (size_t content_size) - The size of the content of the new link
** @return: (t_list*) - The newly created link
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	if (!(link = ft_memalloc(sizeof(t_list))))
		return NULL;
	link->next = NULL;

	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
		return (link);
	}

	link->content = ft_memalloc(content_size);
	ft_memcpy(link->content, content, content_size);
	link->content_size = content_size;

	return (link);
}