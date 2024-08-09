/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:21:49 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/12 17:49:57 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*cop;
	size_t	c;

	cop = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cop)
		return (0);
	c = 0;
	while (c < ft_strlen(s))
	{
		cop[c] = (char) s[c];
		c++;
	}
	cop[c] = '\0';
	return (cop);
}
