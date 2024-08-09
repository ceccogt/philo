/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:47:01 by fgrisost          #+#    #+#             */
/*   Updated: 2023/12/03 15:23:21 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	while (*lst)
	{
		nxt = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = nxt;
	}
}
/*
void	del(void *c)
{
	char *d = (char *) c;
	printf("%s", d);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("ciao");
	node2 = ft_lstnew("come");
	node3 = ft_lstnew("stai");
	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	ft_lstclear(&node1, &del);
}*/
