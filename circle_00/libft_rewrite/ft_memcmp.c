/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:41:57 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/07 19:33:08 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*left;
	unsigned char	*right;

	i = 0;
	left = (unsigned char *)s1;
	right = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (left[i] != right[i])
			return (left[i] - right[i]);
		i++;
	}
	return (0);
}
