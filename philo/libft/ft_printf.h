/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:17:58 by fgrisost          #+#    #+#             */
/*   Updated: 2024/07/17 14:38:38 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, int flag, ...);
void	var_check(const char var, int *c, va_list args);
void	putchar_printf(char var, int *c);
void	putstr_printf(char *str, int *c);
void	putnbr_printf(long k, int *c);
void	putnbr_hex(unsigned long l, int *c, char *b);
void	put_mem_hex(void *str, int *c);

#endif