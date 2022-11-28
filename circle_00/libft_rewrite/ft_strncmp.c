/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:37:18 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/25 12:40:45 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2)
{
    unsigned char left;
    unsigned char right;
    int i;

    i = 0;
    while (s1 && s2 && s1[i] && s2[i]){
        left = s1[i];
        right = s1[i];
        if (left != right)
            return (left-right);
        i++;
    }
    return (0);
}
