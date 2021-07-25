/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:12:25 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/25 14:02:36 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str1;
	char		*str2;

	str1 = (char *)haystack;
	str2 = (char *)needle;
	i = 0;
	if (str2[i] == '\0')
		return (str1);
	while (str1[i])
	{
		j = 0;
		while (str2[j] == str1[i + j] && j < len)
		{
			if (ft_strlen(str2) + i > len)
				return (0);
			if (str2[j + 1] == '\0')
				return (&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
