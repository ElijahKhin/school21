/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:26:20 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:26:21 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t			i;
	size_t			end;

	i = ft_strlen(dest);
	end = i;
	if (!(*src))
		return (i);
	if (size <= i)
		return (size + ft_strlen(src));
	while (*src)
	{
		if (i + 1 < size)
		{
			dest[i] = *src;
			end++;
		}
		src++;
		i++;
	}
	dest[end] = '\0';
	return (i);
}
