/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:32:42 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/21 15:48:12 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((size_t)ft_strlen((char *)s + start) < len)
		sub = (char *)malloc(sizeof(char)
				* (size_t)(ft_strlen((char *)s + start) + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(sub, (char *)s + start, len + 1);
	return (sub);
}
