/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:31:56 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/28 12:26:47 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_hex(unsigned long l, int *c, char *b)
{
	if ((l / 16) != 0)
		putnbr_hex((l / 16), c, b);
	putchar_printf(b[l % 16], c);
}
