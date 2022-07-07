/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:22:54 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/15 17:51:05 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	run;

	run = 0;
	while (n > 0)
	{
		if (((unsigned char *)s1)[run] - ((unsigned char *)s2)[run] != 0)
			return (((unsigned char *)s1)[run] - ((unsigned char *)s2)[run]);
		run++;
		n--;
	}
	return (0);
}
