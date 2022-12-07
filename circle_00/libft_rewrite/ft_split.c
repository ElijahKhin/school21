/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:58:02 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/07 15:32:36 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_of_rows(char const *s, unsigned char c)
{
	int	number_of_rows;

	number_of_rows = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			number_of_rows++;
		while (*s != c && *s)
			s++;
	}
	return (number_of_rows);
}

static void	fill_array(char ***array, char const *s, unsigned char c, int nor)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (nor-- > 0)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		(*array)[j] = malloc(sizeof(char) * (i - start + 1));
		ft_strlcpy((*array)[j++], s + start, i - start + 1);
	}
	(*array)[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		num_of_rows;

	num_of_rows = get_num_of_rows(s, c);
	array = malloc(sizeof(char *) * (num_of_rows + 1));
	fill_array(&array, s, c, num_of_rows);
	return (array);
}
