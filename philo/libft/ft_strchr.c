/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:03:38 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/24 12:18:49 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *) s;
	c = c % 128;
	while (*res != '\0')
	{
		if (*res == c)
			return (res);
		res++;
	}
	if (c == 0)
		return (res);
	else
		return (NULL);
}
/*#include <stdio.h>
int main(void)
{
	char	*d = ft_strchr("tripouille", 't' + 256);
	printf("%s", d);
}*/
