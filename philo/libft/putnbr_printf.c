/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:34:32 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/28 14:07:59 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_printf(long k, int *c)
{
	if (k < 0)
	{
		k = k * -1;
		putchar_printf('-', c);
	}
	if (k < 10)
		putchar_printf((char)(k + 48), c);
	else
	{
		putnbr_printf(k / 10, c);
		putnbr_printf(k % 10, c);
	}
}
