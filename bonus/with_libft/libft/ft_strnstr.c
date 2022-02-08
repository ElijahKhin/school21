/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:25:18 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:25:21 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len;

	if (!(*to_find))
		return ((char *)str);
	len = ft_strlen(to_find);
	while (*str && n >= len)
	{
		n--;
		if (!ft_memcmp(str, to_find, len))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
