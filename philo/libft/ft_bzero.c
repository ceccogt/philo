/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:43:21 by fgrisost          #+#    #+#             */
/*   Updated: 2023/12/03 15:10:43 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}
/*
int	main(void)
{
	char	str[101] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	ft_bzero(str, 42);
	int i = 1;
	while (str[i] == '\0')
		printf("%i\n", i++);
}*/
