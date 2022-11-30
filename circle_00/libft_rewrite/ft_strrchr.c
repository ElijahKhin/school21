/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:08:24 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/30 13:50:21 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;
    int index_of_occur;

    i = 0;
    index_of_occur = -1;
    if ((unsigned char)c == 0)
        return (char *)s + ft_strlen(s);
    while (s && s[i])
    {
        if (s[i] == (unsigned char)c)
            index_of_occur = i;
        i++;
    }
    if (index_of_occur != -1)
        return ((char *)s+index_of_occur);
    return NULL;
} 
