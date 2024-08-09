/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:46:17 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/24 16:59:29 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
	t_list	*l;
	t_list	*q;
	char c = 'e';
	l = (t_list *) malloc(sizeof(t_list));
	q = (t_list *) malloc(sizeof(t_list));
	l->next = NULL;
	q->next = NULL;
	t_list *r = ft_lstlast(l);
	printf("%p\n", q);
	printf("%p\n", r);
}*/
