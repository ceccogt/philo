/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:22:21 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/28 13:36:21 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr_printf(char *str, int *c)
{
	int	i;

	if (!str)
		putstr_printf("(null)", c);
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			putchar_printf(str[i], c);
			i++;
		}
	}
}
