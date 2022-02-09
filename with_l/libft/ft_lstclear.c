/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:31:07 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:31:08 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			next = (*lst)->next;
			del((*lst)->content);
			*lst = next;
		}
		*lst = NULL;
	}
}
