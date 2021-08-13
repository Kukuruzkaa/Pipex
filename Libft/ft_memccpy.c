/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:41:44 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/25 15:54:21 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int			index;
	unsigned char			*dt;
	unsigned char			*sc;

	dt = (unsigned char *)dst;
	sc = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		dt[index] = sc[index];
		if (sc[index] == (unsigned char)c)
			return ((void *)&dt[index + 1]);
		index++;
	}
	return (0);
}
