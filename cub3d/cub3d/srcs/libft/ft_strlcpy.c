/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:11:35 by scoach            #+#    #+#             */
/*   Updated: 2021/05/12 17:41:05 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	if (!src || !dst)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		if (src_len < dstsize)
		{
			ft_memcpy(dst, src, src_len);
			dst[src_len] = '\0';
		}
		else if (dstsize != 0)
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (src_len);
}
