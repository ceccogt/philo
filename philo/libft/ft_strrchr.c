/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:09:38 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/24 13:01:43 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		n;

	c = c % 128;
	n = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			p = (char *) s;
			n = 1;
		}
		s++;
	}
	if (c == 0)
	{
		p = (char *) s;
		return (p);
	}
	if (n == 0)
		return (NULL);
	else
		return (p);
}
