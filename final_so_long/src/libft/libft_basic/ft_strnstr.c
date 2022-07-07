/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:33:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/26 20:54:46 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *strA, const char *little, size_t len)
{
	size_t	l_len;
	size_t	b_len;
	size_t	size;

	if (*little == '\0')
		return ((char *)strA);
	l_len = lb_strlen(little);
	b_len = lb_strlen(strA);
	if (b_len < l_len || len < l_len)
		return (0);
	if (b_len > len)
		size = len;
	else
		size = b_len;
	while (size-- >= l_len)
	{
		if (ft_memcmp(strA, little, l_len) == 0)
			return ((char *)strA);
		strA++;
	}
	return (0);
}
