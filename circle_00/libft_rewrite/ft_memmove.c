/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:53:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/25 15:51:10 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    int i;
    char *from;
    char *to;
    char *tmp;
    
    i = 0;
    to = dst;
    from = (char *)src;
    tmp = malloc(len);
    if (!tmp)
        return (NULL);
    ft_memcpy(tmp, from, len); 
    while (len-- > 0)
    {
        to[i] = tmp[i];
        i++;
    }
    free(tmp);
    return (dst);
}
