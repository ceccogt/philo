/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisost <fgrisost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:30:47 by fgrisost          #+#    #+#             */
/*   Updated: 2024/06/24 15:25:09 by fgrisost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	count(char const *s, char c)
{
	int	i;
	int	co;

	i = 1;
	co = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			co++;
		i++;
	}
	if (s[ft_strlen(s) - 1] == c)
		return (co - 1);
	return (co);
}

int	countchar(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**free_ma(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
	return (NULL);
}

char	**help(char const *s, char c, char **res, int words)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		j = 0;
		res[i] = (char *) malloc((countchar(s, c) + 1) * sizeof(char));
		if (!res[i])
			return (free_ma(res, i));
		while (j < countchar(s, c))
		{
			res[i][j] = s[j];
			j++;
		}
		s = s + j;
		res[i][j] = '\0';
		while (*s == c)
			s++;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (s[0] == '\0')
		return (NULL);
	while (*s == c)
		s++;
	res = (char **) malloc ((count(s, c) + 1) * sizeof (char **));
	if (!res)
		return (NULL);
	words = count(s, c);
	return (help(s, c, res, words));
}
/*include <string.h>
int	main(void)
{
	char **m = ft_split("Tripouille", ' ');
	int i = 0;
	while(1)
	{
		printf("%s\n", m[i]);
		if(!m[i])
			break;
		i++;
	}
}*/
