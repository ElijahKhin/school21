/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:29:15 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/25 14:41:08 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    int i;
    char *twin;

    i = 0;
    twin = (char *)s;
    while (n-- > 0)
    {
        if (twin[i] == (unsigned char)c) 
            return (twin + i);
        i++;
    }
    return (NULL);
}
