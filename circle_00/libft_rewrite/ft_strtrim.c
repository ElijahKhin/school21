/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:37:26 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/01 10:56:49 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    char *new;

    i = 0;
    new = malloc(1);
    if (!s1 || !set || !new)
        return NULL;
    while (*s1)
    {
        if (!ft_strchr(set, *s1))
            new[i++] = *s1;
        s1++;
    }
    new[i] = '\0';
    return new;
}
