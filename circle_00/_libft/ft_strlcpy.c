/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:15:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/19 19:23:46 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*tmp_src;

	tmp_src = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (!dst || !src)
		return (ft_strlen(src));
	while (dstsize-- -1 > 0 && *tmp_src)
		*dst++ = *tmp_src++;
	*dst = '\0';
	return (ft_strlen(src));
}
