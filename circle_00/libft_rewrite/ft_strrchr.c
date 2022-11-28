/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:08:24 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/25 11:18:03 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;
    int index_of_occur;

    i = 0;
    index_of_occur = -1;
    while (s && s[i])
    {
        if (s[i] == c)
            index_of_occur = i;
        i++;
    }
    return ((char *)s+i);
} 
