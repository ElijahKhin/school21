/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:05:50 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:05:51 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	new = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (new == NULL)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{
		new[i] = s1[i];
		i++;
	}
	while (j < ft_strlen((char *)s2))
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
