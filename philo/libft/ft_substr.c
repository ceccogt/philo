/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:11:17 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/14 11:18:18 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	n;

	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = malloc ((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	n = 0;
	if (start <= ft_strlen(s))
	{
		while (len > 0 && s[n + start] != 0)
		{
			sub[n] = s[start + n];
			n++;
			len--;
		}
	}
	sub[n] = '\0';
	return (sub);
}
/*#include <stdio.h>
int main (void)
{
	char *p = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	printf("%s", p);
}*/
