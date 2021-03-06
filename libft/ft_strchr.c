/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:15:09 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/18 18:11:27 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		run;
	char	twin;

	twin = (unsigned char)c;
	run = 0;
	while (str[run])
	{
		if (str[run] == twin)
			return ((char *)str + run);
		run++;
	}
	if (str[run] == twin)
		return ((char *)str + run);
	return (0);
}
