/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:00:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/25 17:46:09 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		counter;
	char	*dst;

	counter = 0;
	while (src[counter])
	{
		counter++;
	}
	dst = malloc(sizeof(*src) * (counter + 1));
	if (NULL == dst)
	{
		return (NULL);
	}
	while (counter >= 0)
	{
		dst[counter] = src[counter];
		counter--;
	}
	return (dst);
}
