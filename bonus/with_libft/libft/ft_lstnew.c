/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:30:25 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:30:29 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*current;

	current = (t_list *)malloc(sizeof(t_list));
	if (!current)
		return (NULL);
	current->content = content;
	current->next = NULL;
	return (current);
}
