/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:12:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/28 18:32:19 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len) 
{   
    size_t i;

    i = 0;
    while ((ft_strlen((char *)haystack + i) >= ft_strlen(needle)) && (len > 0)) 
    {
        if (!ft_memcmp(haystack + i, needle, ft_strlen(needle)))
            return ((char *)haystack + i);
        i++;
        len--;
    }
    return NULL;
}


int main(void) {
    printf("%s\n", ft_strnstr("some_some", "some", 4));
}*/
