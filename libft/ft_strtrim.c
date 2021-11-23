/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:05:14 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/21 16:16:24 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_in_set(char c, char const *set)
{
	int	run;

	run = 0;
	while (set[run])
		if (set[run++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		run;
	int		end;
	char	*ret;

	if (set == NULL)
		return (ft_strdup(s));
	if (s == NULL)
		return (ft_strdup(""));
	end = ft_strlen(s);
	run = 0;
	while (s[run] && char_in_set(s[run], set))
		run++;
	while (end > run && char_in_set(s[end - 1], set))
		end--;
	if (run >= end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - run + 1));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + run, end - run + 1);
	return (ret);
}
