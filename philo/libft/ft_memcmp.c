/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:03:16 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/12 11:12:25 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	while (*str1 == *str2 && n > 1)
	{
		n--;
		str1++;
		str2++;
	}
	if (*str1 == *str2 || n == 0)
		return (0);
	else
	{
		if (*str1 > *str2)
			return (1);
		else
			return (-1);
	}
}
