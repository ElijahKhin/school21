/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:20:47 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/28 17:12:03 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    int i;
    int j;
    char *src;
    char *find;

    i = 0;
    j = 0;
    src = (char *)haystack;
    find = (char *)needle;
    
    if ((!find || !find[0]) && src)
        return (src);
    while (src[i] && len-- > 0)
    {
        while (src[i] == find[j] && src[i] && len-- > 0)
        {
            i++;
            j++;
        }
        printf("%d - %d", i, j);
        if ((size_t)j == ft_strlen(find) && len > 0)
            return (src + (i - j));
        i = i - j + 1;
        j = 0;
        len = len - j + 1;
    }
    return (NULL);
}
