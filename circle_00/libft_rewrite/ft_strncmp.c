/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:37:18 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/30 13:57:27 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char left;
    unsigned char right;
    int i;

    i = 0;
    while ((s1[i] || s2[i]) && n-- > 0)
    {
        left = s1[i];
        right = s2[i++];
        if (left != right)
            return left-right;
    }
    return 0;
}
