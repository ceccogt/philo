/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:29:52 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/24 16:42:32 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* int main()
{
	t_list	*l;
	t_list	*q;
	l = (t_list *) malloc(sizeof(t_list));
	q = (t_list *) malloc(sizeof(t_list));
	l->next = q;
	q->next = NULL;
	int len = ft_lstsize(l);
	printf("%i", len);
} */