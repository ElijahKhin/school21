/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:24:56 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:25:01 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	find_len(const char *s, const char *set)
{
	size_t		len;
	size_t		res;
	int			i;

	len = ft_strlen(s);
	res = len;
	i = 0;
	while (s[i] && check(s[i], set) && res > 0)
	{
		res--;
		i++;
	}
	len--;
	while (s[len] && check(s[len], set) && res > 0)
	{
		res--;
		len--;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		new_len;
	char		*res;
	char		*p;

	if (!s1 || !set)
		return (NULL);
	new_len = find_len(s1, set);
	res = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!res)
		return (NULL);
	p = res;
	if (new_len > 0)
	{
		while (*s1 && check(*s1, set))
			s1++;
		while (new_len--)
		{
			*res = *s1;
			res++;
			s1++;
		}
	}
	*res = '\0';
	return (p);
}
