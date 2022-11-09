/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:19:20 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/19 18:00:55 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *strA, void *strB, size_t n)
{
	void	*t;

	if (strA && strB)
	{
		t = malloc(n);
		if (t == NULL)
			return (NULL);
		ft_memcpy(t, strB, n);
		ft_memcpy(strA, t, n);
		free(t);
	}
	return (strA);
}
