/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:19:20 by fgrisost          #+#    #+#             */
/*   Updated: 2024/07/17 14:40:19 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, int flag, ...)
{
	va_list	args;
	int		c;
	int		i;

	i = 0;
	c = 0;
	if (flag == 0)
		return -1;
	va_start(args, flag);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			var_check(str[i + 1], &c, args);
			i++;
		}
		else
			putchar_printf(str[i], &c);
		i++;
	}
	va_end(args);
	return (c);
}
/*
int	main()
{
	int c = ft_printf("%s\n", 36);
	printf("%x", -36);
 	printf("\n%i\n", c); 
}*/