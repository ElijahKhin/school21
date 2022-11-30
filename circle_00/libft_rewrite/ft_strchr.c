/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:08:24 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/30 13:30:21 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    while (s && *s != (unsigned char)c && *s != '\0')
        s++;
    if (*s == (unsigned char)c)
        return ((char *)s);
    return NULL;
} 
