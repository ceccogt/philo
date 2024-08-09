/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:59:53 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/28 12:47:52 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_mem_hex(void *str, int *c)
{
	unsigned long	mem;

	if (str == NULL)
		putstr_printf("(nil)", c);
	else
	{
		mem = (unsigned long)str;
		putstr_printf("0x", c);
		putnbr_hex(mem, c, "0123456789abcdef");
	}
}
