/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:30:00 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:30:01 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*src;

	i = 0;
	src = s;
	while (i < n)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		i++;
		src++;
	}
	return (NULL);
}
