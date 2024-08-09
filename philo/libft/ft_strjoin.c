/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:19:19 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/14 11:25:12 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*su;
	int		c;

	su = (char *) malloc ((ft_strlen(s1) + (ft_strlen(s2) + 1)) * sizeof(char));
	if (!su)
		return (NULL);
	c = 0;
	while (s1[c] != '\0')
	{
		su[c] = s1[c];
		c++;
	}
	while (*s2 != '\0')
	{
		su[c] = *s2;
		c++;
		s2++;
	}
	su[c] = '\0';
	return (su);
}
