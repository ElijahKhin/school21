/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:55:48 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/25 14:13:21 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
    int i;
    char *twin;

    i = 0;
    twin = b;
    while (len-- > 0)
        twin[i++] = (unsigned char)c;
    return (b);
}
