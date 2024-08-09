/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:14:53 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/12 11:30:21 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*k;
	size_t		i;

	if (ft_strlen(little) == 0)
		return ((char *) big);
	while (*big != '\0' && len > 0)
	{
		if (*big == little[0])
		{
			k = big;
			i = 0;
			while (*big == little[i] && little[i] != '\0' && (len - i > 0))
			{
				i++;
				big++;
			}
			if (i == ft_strlen(little))
				return ((char *) k);
			big = k;
		}
		big++;
		len--;
	}
	return (NULL);
}
