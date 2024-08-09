/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:26:06 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/14 13:29:53 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <stdio.h>

const char	*front(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	cont;

	while (*s1 != 0)
	{
		i = 0;
		cont = 0;
		while (set[i] != 0)
		{
			if (*s1 == set[i])
			{
				s1++;
				cont = 1;
			}
			i++;
		}
		if (cont == 0)
			break ;
	}
	return (s1);
}

const char	*back(char const *s1, char const *set)
{
	unsigned int	i;
	int				l;
	unsigned int	cont;

	l = ft_strlen(s1) - 1;
	while (l >= 0)
	{
		i = 0;
		cont = 0;
		while (set[i] != 0)
		{
			if (s1[l] == set[i])
			{
				l--;
				cont = 1;
			}
			i++;
		}
		if (cont == 0)
			break ;
	}
	if (l < 0)
		return (NULL);
	return (&s1[l]);
}

size_t	dist(char *s1, char *s2)
{
	size_t	len;

	len = 0;
	while (&s1[len] != &s2[1])
		len++;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*r;
	char			*s;
	char			*s2;
	size_t			len;
	unsigned int	i;

	if (!s1 || !set)
		return ((char *) s1);
	s2 = (char *) back(s1, set);
	s = (char *) front(s1, set);
	if (!s2)
		return (ft_calloc(1, 1));
	len = dist(s, s2);
	r = malloc ((len + 1) * sizeof (char));
	if (!r)
		return (0);
	i = 0;
	while (&s[i] != (s2 + 1))
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
/*
#include <unistd.h>
int main()
{
	char *str = ft_strtrim("abbaabbbbbbba", "ab");
	printf("%s", str);
}*/