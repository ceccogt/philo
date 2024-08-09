/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:27:38 by fgrisost          #+#    #+#             */
/*   Updated: 2023/12/03 15:15:32 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	c;

	c = 0;
	if (nmemb * size > 2147483647)
		return (NULL);
	else
	{
		ptr = (char *) malloc(nmemb * size * sizeof(char));
		if (!ptr)
			return (0);
		while (c < nmemb * size)
		{
			ptr[c] = 0;
			c++;
		}
		return (ptr);
	}
}

/* int	main(void)
{
	char	*str = ft_calloc(10, sizeof(char));
	free(str);
} */
