/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:02:50 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/24 10:49:31 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	slen;

	i = 0;
	slen = 0;
	while (src[slen] != '\0')
		slen++;
	while (src[i] != '\0' && size > 1)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	if (size != 0)
		dst[i] = '\0';
	return (slen);
}
