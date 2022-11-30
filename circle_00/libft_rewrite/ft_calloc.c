/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:56:29 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/30 10:30:28 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;

    if (count == SIZE_MAX && size == SIZE_MAX)
        return NULL;
    ptr = malloc(count * size);
    if (!ptr)
        return NULL;
    ft_bzero(ptr, count*size);
    return ptr;
}
