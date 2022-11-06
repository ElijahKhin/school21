/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:14:02 by scoach            #+#    #+#             */
/*   Updated: 2021/05/12 21:24:27 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_triglen(char const *l, char const *s, int ln, char o)
{
	size_t			part_len;
	size_t			sln;
	unsigned int	i;
	int				j;

	sln = ft_strlen(s);
	part_len = 0;
	j = 0;
	while (j >= 0 && j < ln)
	{
		i = 0;
		while (i < sln)
		{
			if ((l[j] == s[i] && o == 's')
				|| (l[ln - j - 1] == s[i] && o == 'e'))
			{
				part_len = ++j;
				break ;
			}
			else if (i == sln - 1)
				j = -1;
			i++;
		}
	}
	return (part_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s_len;
	size_t	start_len;
	size_t	end_len;

	if (!s1)
		return (NULL);
	s_len = ft_strlen(s1);
	if (!(ft_strlen(set) == 0))
	{
		end_len = ft_triglen(s1, set, s_len, 'e');
		start_len = ft_triglen(s1, set, s_len, 's');
	}
	else
	{
		end_len = 0;
		start_len = 0;
	}
	return (ft_substr(s1, start_len, (s_len - (start_len + end_len))));
}
