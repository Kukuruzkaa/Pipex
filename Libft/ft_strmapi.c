/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:29:27 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/27 16:32:10 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	int		size;
	char	*s2;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	index = 0;
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	while (index < size)
	{
		s2[index] = (*f)(index, s[index]);
		index++;
	}
	s2[index] = '\0';
	return (s2);
}
