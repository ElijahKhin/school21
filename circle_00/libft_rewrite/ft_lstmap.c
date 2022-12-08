/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:40:00 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 20:23:29 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result_lst;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	result_lst = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&result_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&result_lst, new);
	}
	return (result_lst);
}
