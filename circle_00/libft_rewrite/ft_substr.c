/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:17:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/30 19:09:20 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int i;
    size_t len_of_sub;
    size_t len_of_s;
    char *sub_str;

    i = 0;
    len_of_s = ft_strlen(s);
    if (len_of_s >= start+len)
        len_of_sub = len + 1;
    else
        len_of_sub = len_of_s - start + 2;
    sub_str = malloc(sizeof(char) * len_of_sub);
    if (!sub_str)
        return NULL;
    while (len_of_sub-- > 1)
        sub_str[i++] = s[start++];
    sub_str[i] = '\0';
    return sub_str;
}
