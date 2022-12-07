/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:17:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/07 19:53:31 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub_str;

	i = 0;
	if (ft_strlen(s) < start)
		return (malloc(1));
	else
		sub_str = malloc(1);
	if (!sub_str || !s)
		return (NULL);
	while (len-- > 0 && s[start])
		sub_str[i++] = s[start++];
	sub_str[i] = '\0';
	return (sub_str);
}
