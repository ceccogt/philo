/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:45:23 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/24 11:29:36 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	res;

	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	res = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i] != '\0')
		i++;
	l = 0;
	while (src[l] != '\0' && i < size - 1)
	{
		dst[i] = src[l];
		i++;
		l++;
	}
	dst[i] = '\0';
	return (res);
}
/*int	main(void)
{
	char dest[8] = "cane ";
	char src[4] = "123";
	size_t size = 0;
	size = ft_strlcat(dest, src, size);
	printf("%ld\n", size);
	printf("%s\n", dest);
}*/
