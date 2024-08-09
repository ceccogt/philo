/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:49:09 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/16 19:49:12 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*de;
	char	*sr;

	de = (char *) dest;
	sr = (char *) src;
	if (!src && !dest)
		return (de);
	i = 0;
	while (n > 0)
	{
		de[i] = sr[i];
		i++;
		n--;
	}
	return (de);
}
