/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 09:15:23 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/25 11:44:31 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return (0);
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (j < (dstsize - 1) && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
