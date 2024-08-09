/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:04:06 by fgrisost          #+#    #+#             */
/*   Updated: 2023/11/22 12:16:22 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	ln = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ln = ln * -1;
	}
	if (ln >= 10)
	{
		ft_putnbr_fd((int)(ln / 10), fd);
		ft_putnbr_fd((int)(ln % 10), fd);
	}
	else
	{
		c = ln + 48;
		write(fd, &c, 1);
	}
}
/*
int main()
{
	ft_putnbr_fd(-156, 1);
}*/