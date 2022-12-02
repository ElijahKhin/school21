/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:17:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/01 10:36:27 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    char *new;

    i = 0;
    new = malloc(1);
    if (!new || !s1 || !s2)
        return NULL;
    while (*s1)
       new[i++] = *s1++;
    while(*s2)
        new[i++] = *s2++;
    new[i] = '\0';
    return new;
}
