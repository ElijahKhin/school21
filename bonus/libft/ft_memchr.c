/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:49:11 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/19 17:58:36 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	int	run;

	run = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[run] == ((unsigned char)c))
			return (s + run);
		run++;
		n--;
	}
	return (NULL);
}
