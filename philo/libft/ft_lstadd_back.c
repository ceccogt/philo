/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:00:19 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/25 12:10:03 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cpy;

	if (*lst == NULL)
		*lst = new;
	else
	{
		cpy = *lst;
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = new;
	}
}
/*
void printContent(void *c)
{
	unsigned char	*up;

	up = (unsigned char *) c;
	if (up == NULL)
		printf("%c", *up);
	write(1, "a", 1);
}

void printList(t_list *list) 
{
    while (list) {
        printf("Content: ");
        printContent(list->content);
		write(1, "b", 1);
        if (list->next != NULL)
        	printf(" --> ");
		list = list->next;
    }
    printf("\n");
}

int main()
{
	t_list	*l;
	t_list	*q;
	t_list	*f;
	t_list	*new;
	unsigned char c1 = 'l';
	unsigned char c2 = 'q';
	unsigned char c3 = 'f';
	unsigned char c4 = 'n';
	l = (t_list *) malloc(sizeof(t_list));
	q = (t_list *) malloc(sizeof(t_list));
	f = (t_list *) malloc(sizeof(t_list));
	new = (t_list *) malloc(sizeof(t_list));
	l->next = NULL;
	l->content = NULL;
	q->content = &c2;
	f->content = &c3;
	new->content = &c4;
	q->next = f;
	f->next = NULL;
	new->next = NULL;
	ft_lstadd_back(NULL, new);
	printList(l);
}*/