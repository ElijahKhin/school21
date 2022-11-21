/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:06:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:06:23 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		occ;
	char	ch;
	char	*str;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	occ = -1;
	while (i <= ft_strlen((char *)str))
	{
		if (str[i] == ch)
			occ = i;
		i++;
	}
	if (occ != -1)
		return ((char *)str + occ);
	return (NULL);
}
