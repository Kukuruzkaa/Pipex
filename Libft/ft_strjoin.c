/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 08:26:21 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/31 14:09:33 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		str1len;
	int		str2len;
	int		i;
	int		j;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	str1len = ft_strlen(s1);
	str2len = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (str1len + str2len + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (i++ < str1len)
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		s3[str1len + j] = s2[j];
		j++;
	}
	s3[str1len + str2len] = '\0';
	return (s3);
}
