/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:01:36 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/03 16:43:38 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char **ret)
{
	long long int	run;

	run = 0;
	while (ret[run])
		free(ret[run++]);
	free(ret);
	return (NULL);
}

t_kill_split	surgery(char const *s, char c)
{
	t_kill_split	saw;
	int				run;

	saw.junk = 0;
	saw.real_row_length = 0;
	saw.jump_to_next_row = 0;
	run = 0;
	while (s[saw.jump_to_next_row] && s[saw.jump_to_next_row] == c)
	{
		saw.junk++;
		saw.jump_to_next_row++;
	}
	while (s[saw.jump_to_next_row] && s[saw.jump_to_next_row] != c)
	{
		saw.jump_to_next_row++;
		saw.real_row_length++;
	}
	while (s[saw.jump_to_next_row] && s[saw.jump_to_next_row] == c)
		saw.jump_to_next_row++;
	return (saw);
}

int	exc(char const *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}

int	number_of_real_rows(char const *s, char c)
{
	int				num_rows;
	t_kill_split	saw;

	num_rows = 0;
	saw.jump_to_next_row = 0;
	if (exc(s, c))
		return (0);
	while (saw.jump_to_next_row < lb_strlen((char *)s))
	{
		saw.jump_to_next_row += surgery(s + saw.jump_to_next_row, c)
			.jump_to_next_row;
		num_rows++;
	}
	return (num_rows);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		run;
	int		filled_rows;

	run = 0;
	filled_rows = 0;
	ret = (char **)malloc(sizeof(char *) * (number_of_real_rows(s, c) + 1));
	if (!ret)
		return (NULL);
	while (filled_rows < number_of_real_rows(s, c))
	{
		ret[filled_rows] = (char *)malloc(sizeof(char) * (surgery(s + run, c)
					.real_row_length + 1));
		if (!ret[filled_rows])
			return (ft_free(ret));
		ft_strlcpy(ret[filled_rows],
			s + run + surgery(s + run, c).junk,
			surgery(s + run, c).real_row_length + 1);
		filled_rows++;
		run += surgery(s + run, c).jump_to_next_row;
	}
	ret[filled_rows] = NULL;
	return (ret);
}
