/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:03:46 by ddiakova          #+#    #+#             */
/*   Updated: 2021/02/01 11:21:07 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	if (c == 0)
		return ((char *)&s[index]);
	while (index >= 0)
	{
		if ((int)s[index] == c)
			return ((char *)&s[index]);
		index--;
	}
	return (NULL);
}
