/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:32:42 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/25 18:28:32 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)lb_strlen(s) < start)
		return (ft_strdup(""));
	if ((size_t)lb_strlen((char *)s + start) < len)
		sub = malloc(sizeof(char)
				* (size_t)(lb_strlen((char *)s + start)+1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(sub, (char *)s + start, len + 1);
//	free((char *)s);
	return (sub);
}
