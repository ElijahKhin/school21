/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:12:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/07 19:50:01 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_of_needle;

	i = 0;
	len_of_needle = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (ft_strlen((char *)haystack + i) >= len_of_needle && len > 0)
	{
		if (!ft_memcmp(haystack + i, needle, len_of_needle)
			&& len_of_needle <= len)
			return ((char *)haystack + i);
		i++;
		len--;
	}
	return (NULL);
}
