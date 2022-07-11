/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:47:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/11 22:58:31 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>

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

int main(void)
{
	printf("%s", ft_strchr("Hello", 'l'));
}
