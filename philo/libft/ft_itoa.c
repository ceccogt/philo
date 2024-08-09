/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:58:28 by fgrisost          #+#    #+#             */
/*   Updated: 2023/10/14 19:21:46 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*putnbr(long n, long c)
{
	char	*res;

	res = (char *) malloc((c + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[c] = '\0';
	while (n > 0)
	{
		res[c - 1] = (n % 10) + 48;
		if (n == 10)
			n++;
		n = n / 10;
		c--;
	}
	return (res);
}

char	*putnbrneg(long n, long c)
{
	char	*res;

	res = (char *) malloc((c + 2) * sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '-';
	res[c + 1] = '\0';
	n = n * -1;
	while (n > 0)
	{
		res[c] = (n % 10) + 48;
		if (n == 10)
			n++;
		n = n / 10;
		c--;
	}
	return (res);
}

char	*zero(long c)
{
	char	*res;

	res = (char *) malloc(2 * sizeof(char));
	if (!res)
		return (NULL);
	c = 0;
	res[c] = c + 48;
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	long		c;
	long		nb;
	long		ln;

	ln = n;
	c = 0;
	nb = ln;
	while (nb != 0)
	{
		c++;
		nb = nb / 10;
	}
	if (n < 0)
		return (putnbrneg(ln, c));
	if (n > 0)
		return (putnbr(ln, c));
	return (zero(c));
}
/*
int main(){
	char *str = ft_itoa(-2147483648);
	printf("stringa: %s", str);
}*/