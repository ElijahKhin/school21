/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:47:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/19 20:09:32 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	tmp;
	char			*str;
	
	tmp = c;
	if (*s == 0)
	{
		if (c == 0)
			return ((char *)s);
		return (0);
	}
	while (*s)
	{
		if (*s == tmp)
			str = (char *)s;
		s++;
	}
	if (*s == tmp)
	{
		str = (char *)s;
		return (str);
	}
	return (str);
}
