/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:54:14 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/27 12:50:38 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	index;
	char			*dt;
	char			*sc;

	dt = (char *)dst;
	sc = (char *)src;
	if (!n || dt == sc)
		return (dt);
	index = 0;
	while (index < n)
	{
		dt[index] = sc[index];
		index++;
	}
	return (dst);
}
