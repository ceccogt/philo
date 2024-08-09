/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:53:14 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/24 15:23:05 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
void printContent(void *c)
{
	unsigned char	*up;

	up = (unsigned char *) c;
	printf("%c", *up);
}

void printList(t_list *list) 
{
    while (list != NULL) {
        printf("Content: ");
        printContent(list->content);
        list = list->next;
        if (list != NULL) {
            printf(" --> ");
        }
    }
    printf("\n");
}

int main()
{
	char c = 'c';
	char b = 'b';
	t_list *l = ft_lstnew(&c);
	t_list *l1 = ft_lstnew(&b);
	ft_lstadd_front(&l, l1);
	printList(l1);
}*/