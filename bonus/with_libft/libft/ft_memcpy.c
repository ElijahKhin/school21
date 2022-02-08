/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:28:55 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:28:57 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*s;

	if (dest == src)
		return (dest);
	i = 0;
	p = dest;
	s = src;
	while (i < n)
	{
		*p = *s;
		i++;
		s++;
		p++;
	}
	return (dest);
}
