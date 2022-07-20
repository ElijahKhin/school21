/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:36:23 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/20 21:41:11 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int 	result_len;
	int		max_append;
	int		dst_len;
	char	*tmp_src;
	char	*tmp_dst;

	tmp_dst = dst;
	dst_len = ft_strlen(tmp_dst);
	result_len = dst_len + ft_strlen(src);
	max_append = dstsize - dst_len;
	tmp_src = (char *)src;
	if (dstsize == 0 || dst_len + 1 > (int)dstsize)
		return (result_len);
	if (!dst || !src)
		return (result_len);
	tmp_dst += dst_len;
	ft_strlcpy(tmp_dst, src, (size_t)max_append);
	return (result_len);
}
/*
int main(void)
{
	char some_str[11] = "BBBB";
	char some_str2[11] = "BBBB";
	printf("%zu\n", ft_strlcat(some_str, "AAAAAAAAA", 6));
	printf("%zu\n", strlcat(some_str2, "AAAAAAAAA", 6));
	printf("%s %s %zu %zu %d %d\n", some_str, some_str2, ft_strlen(some_str), ft_strlen(some_str2), !strcmp(some_str, "BBBBA"), !strcmp(some_str2, "BBBBA"));
}*/
