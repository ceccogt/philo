/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:10:48 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/26 17:39:05 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstiter_fake(t_list *lst, void *(*f)(void *))
{
	t_list	*cpy;

	cpy = lst;
	while (lst)
	{
		lst->content = f(lst->content);
		lst = lst->next;
	}
	lst = cpy;
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*res;

	if (!lst)
		return (NULL);
	cpy = ft_lstnew(lst->content);
	res = cpy;
	lst = lst->next;
	while (lst)
	{
		cpy->next = ft_lstnew(lst->content);
		if (!(cpy->next))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		cpy = cpy->next;
		lst = lst->next;
	}
	return (ft_lstiter_fake(res, f));
}
