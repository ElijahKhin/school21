/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:56:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/26 13:12:39 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	run;
	size_t	dest_len;
	size_t	src_len;

	dest_len = lb_strlen(dest);
	src_len = 0;
	while (src[src_len])
		src_len++;
	run = 0;
	if (dstsize < dest_len + 1)
		return (dstsize + src_len);
	if (dstsize > dest_len + 1)
	{
		while (dstsize - dest_len - 1 - run > 0 && src[run] != '\0')
		{
			dest[dest_len + run] = src[run];
			run++;
		}
	}
	dest[dest_len + run] = '\0';
	return (dest_len + src_len);
}
