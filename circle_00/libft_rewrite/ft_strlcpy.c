/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:00:35 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/07 19:43:52 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while (dstsize > 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
