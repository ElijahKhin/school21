/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:30:07 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:30:08 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*s;

	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n)
	{
		*p = *s;
		p++;
		if (*s == (unsigned char)c)
			return ((void *)p);
		s++;
		n--;
	}
	return (NULL);
}
