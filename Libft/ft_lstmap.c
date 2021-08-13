/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:21:20 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/30 15:07:49 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*item;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	item = NULL;
	while (lst)
	{
		if (item != ft_lstnew((f)(lst->content)))
		{
			while (new)
			{
				item = new->next;
				(*del)(new->content);
				free(new);
				new = item;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new, item);
		lst = lst->next;
	}
	return (new);
}
