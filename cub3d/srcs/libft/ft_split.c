/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:09:25 by scoach            #+#    #+#             */
/*   Updated: 2021/05/12 22:50:35 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **arr)
{
	int	k;

	k = 0;
	while (arr[k] != NULL)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}

static size_t	ft_delimeter_count(char const *s, char c)
{
	int		k;
	int		i;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (k);
}

static char	**ft_newarr(char const *s, char c, char **arr)
{
	unsigned int	i;
	unsigned int	j;
	int				k;

	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
		{
			arr[k] = ft_substr(s, j, i - j);
			if (arr[k] == NULL)
				return (NULL);
			k++;
		}
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	int				k;

	if (!s)
		return (NULL);
	k = 0;
	k = ft_delimeter_count(s, c);
	arr = (char **)malloc(sizeof(char **) * (k + 1));
	if (!arr)
		return (NULL);
	arr = ft_newarr(s, c, arr);
	if (arr == NULL)
	{
		ft_free(arr);
		return (NULL);
	}
	return (arr);
}
