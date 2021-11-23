/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:17:09 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/18 17:46:22 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	run;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = 0;
	while (src[src_len])
		src_len++;
	run = 0;
	if (dstsize == 0)
		return (src_len);
	while (dstsize - 1 - run > 0 && src[run] != '\0')
	{
		dest[run] = src[run];
		run++;
	}
	dest[run] = '\0';
	return (src_len);
}
