/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:15:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/14 21:46:19 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int tmp_size;
	char *tmp_src;

	tmp_size = (int)dstsize;
	tmp_src = (char *)src;
	if (dstsize == 0)
		return (0);
	if (!dst || !src)
		return (0);
	while (tmp_size-- -1 > 0 && tmp_src)
		*dst++ = *tmp_src++;
	*dst = '\0';
	return (ft_strlen(src));
}
