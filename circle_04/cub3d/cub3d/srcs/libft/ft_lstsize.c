/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:50:59 by scoach            #+#    #+#             */
/*   Updated: 2021/05/12 21:14:10 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	ptr = lst;
	i = 0;
	if (lst)
		i++;
	else
		return (i);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
