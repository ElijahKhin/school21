/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:10:50 by scoach            #+#    #+#             */
/*   Updated: 2021/05/12 17:24:56 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s[0] == (unsigned char)c)
		return ((char *)s);
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}
