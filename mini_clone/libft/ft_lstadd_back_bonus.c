/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:04:13 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:04:14 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newlist)
{
	if (*alst == NULL)
	{
		*alst = newlist;
		newlist->next = NULL;
	}
	else
		ft_lstlast(*alst)->next = newlist;
}
