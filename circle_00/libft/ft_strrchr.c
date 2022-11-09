/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:29:23 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/19 21:35:05 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	run;
	int	found;

	found = -1;
	run = 0;
	while (str[run])
	{
		if (str[run] == ((char)c))
			found = run;
		run++;
	}
	if (found >= 0)
		return ((char *)str + found);
	if (str[run] == (char)c)
		return ((char *)str + run);
	return (NULL);
}
