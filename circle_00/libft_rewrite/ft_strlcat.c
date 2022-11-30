/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:45:53 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/29 16:27:53 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t allowed_len;
    size_t init_dst_len;

    i = 0;
    init_dst_len = ft_strlen(dst);
    allowed_len = dstsize - init_dst_len - 1;
    if (init_dst_len + 1 > dstsize)
        return dstsize + ft_strlen(src);
    while (allowed_len-- > 0 && src[i])
    {
        dst[init_dst_len+i] = src[i];
        i++;
        dst[init_dst_len+i] = '\0';
    }
    return init_dst_len + ft_strlen(src);
}
