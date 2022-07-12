/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:47:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/12 20:16:14 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	ft_strchr(const char *s, int c)
{
	char *str;
	
	str = (char *)s;
	if (*str == c)
		return (str);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}
