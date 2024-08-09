/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:07:43 by fgrisost          #+#    #+#             */
/*   Updated: 2023/12/20 20:27:29 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	var_check(const char var, int *c, va_list args)
{
	if (var == 'c')
		putchar_printf((char)(va_arg(args, int)), c);
	if (var == 's')
		putstr_printf((va_arg(args, char *)), c);
	if (var == 'd' || var == 'i')
		putnbr_printf(va_arg(args, int), c);
	if (var == 'u')
		putnbr_printf((unsigned int)va_arg(args, int), c);
	if (var == 'x')
		putnbr_hex((unsigned int)va_arg(args, int), c, "0123456789abcdef");
	if (var == 'X')
		putnbr_hex((unsigned int)va_arg(args, int), c, "0123456789ABCDEF");
	if (var == 'p')
		put_mem_hex(va_arg(args, void *), c);
	if (var == '%')
		putchar_printf('%', c);
}
