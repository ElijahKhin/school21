/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:47:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/12 20:16:43 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	ft_strrchr(const char *s, int c)
{
	int i;
	char *str;
	
	i = 0;
	if (s[i] == c)
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == c)
			str = (char *)s + i;
		i++;
	}
	if (str)
		return (str);
	return (0);
}
