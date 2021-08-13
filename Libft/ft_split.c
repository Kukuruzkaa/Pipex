/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:31:42 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/28 09:26:33 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counting_words(char const *s, char c)
{
	int	index;
	int	nombre;

	index = 0;
	nombre = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index] && s[index] != c)
			nombre++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (nombre);
}

static char	*ft_fillword(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	int		y;
	int		words;
	char	**tab;

	words = ft_counting_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	x = 0;
	y = 0;
	while (s[x])
	{
		while (s[x] && s[x] == c)
			x++;
		if (s[x] && s[x] != c)
		{
			tab[y++] = ft_fillword(&s[x], c);
			while (s[x] && s[x] != c)
				x++;
		}
	}
	tab[y] = NULL;
	return (tab);
}
