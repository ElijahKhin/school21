/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:47:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/19 19:52:38 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	ft_strchr(const char *s, int c)
{
	char *str;
	unsigned char tmp;

	tmp = c;
	str = (char *)s;
	if (*str == tmp)
		return (str);
	while (*str)
	{
		if (*str == tmp)
			return (str);
		str++;
	}
	if (*str == tmp)
		return (str);
	return (0);
}
