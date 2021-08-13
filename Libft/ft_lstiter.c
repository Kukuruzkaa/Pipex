/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:03:12 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/30 13:06:46 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*temp;

	temp = lst;
	if (!temp)
		return ;
	while (temp != NULL)
	{
		(f)(temp->content);
		temp = temp->next;
	}
}
