/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:11:57 by fgrisost          #+#    #+#             */
/*   Updated: 2024/05/26 17:40:52 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	segno;
	long	n;

	segno = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			segno = -1;
		nptr++;
	}
	n = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		n = n * 10 + (*nptr - 48);
		nptr++;
	}
	return (n * segno);
}

/* int	main(void)
{
	int a = ft_atoi("   ---153");
	printf("%i", a);
} */
