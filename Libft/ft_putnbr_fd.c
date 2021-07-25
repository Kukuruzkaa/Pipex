/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:40:25 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/25 14:47:13 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (fd < 0)
		return ;
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		nb = 2147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nb * -1, fd);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd((nb + 48), fd);
}
