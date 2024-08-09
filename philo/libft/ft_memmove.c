/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:23:42 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/24 10:50:53 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static void	move(unsigned char *de, const unsigned char *sr, size_t n)
{
	size_t	i;

	i = 0;
	if (sr < de)
	{
		de = de + n;
		sr = sr + n;
		while (n--)
		{
			*(--de) = *(--sr);
		}
	}
	else
	{
		while (n-- > 0)
		{
			de[i] = sr[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*de;
	const unsigned char	*sr;

	if (dest == NULL && src == NULL)
		return (NULL);
	de = (unsigned char *) dest;
	sr = (const unsigned char *) src;
	move(de, sr, n);
	return (de);
}
