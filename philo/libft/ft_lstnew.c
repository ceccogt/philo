/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:34:39 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/24 14:46:56 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*l;
	unsigned char	*up;

	up = (unsigned char *) content;
	l = (t_list *) malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->content = up;
	l->next = NULL;
	return (l);
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
	char p = 'c';
	t_list *l = ft_lstnew(&p);
	printList(l);

}
*/