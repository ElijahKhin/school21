/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:30:36 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:30:37 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*first_node;

	if (!lst || !f || !del)
		return (NULL);
	current = ft_lstnew(f(lst->content));
	if (!current)
		return (NULL);
	first_node = current;
	while (lst)
	{
		if (lst->next)
		{
			current->next = ft_lstnew(f(lst->next->content));
			if (!(current->next))
			{
				ft_lstclear(&first_node, del);
				return (NULL);
			}
			current = current->next;
		}
		lst = lst->next;
	}
	return (first_node);
}
