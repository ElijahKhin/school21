/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:53:14 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 20:22:33 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ring;

	ring = malloc(sizeof(t_list));
	if (!ring)
		return (NULL);
	ring->content = content;
	ring->next = NULL;
	return (ring);
}
