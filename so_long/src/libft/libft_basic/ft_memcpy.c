/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:44:05 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/19 21:25:40 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *strA, const void *strB, size_t n)
{
	int	run;

	run = 0;
	while (n > 0)
	{
		((unsigned char *)strA)[run] = ((unsigned char *)strB)[run];
		n--;
		run++;
	}
	return (strA);
}
