/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:09:51 by scoach            #+#    #+#             */
/*   Updated: 2022/03/08 19:39:29 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	ft_arrtostr(t_data *data, int aln, char ***tmp, char **second)
{
	int		i;
	char	*now;

	*second = ft_strdup((*tmp)[1]);
	if (second == NULL)
		ft_context_free_err(data, tmp, aln, "ft_arrtostr malloc");
	i = 2;
	while (i < aln)
	{
		now = ft_strjoin(*second, (*tmp)[i]);
		free(*second);
		if (now == NULL)
			ft_context_free_err(data, tmp, aln, "ft_arrtostr malloc");
		*second = ft_strdup(now);
		free(now);
		if (*second == NULL)
			ft_context_free_err(data, tmp, aln, "ft_arrtostr malloc");
		i++;
	}
}

static void	ft_fill_tmp_rgb(t_data *data, char ***tmp, char **frst, char **sec)
{
	(*tmp)[0] = ft_strdup(*frst);
	free(*frst);
	if ((*tmp)[0] == NULL)
		ft_context_free_err(data, tmp, 2, "ft_conc_tmp malloc");
	(*tmp)[1] = ft_strdup(*sec);
	free(*sec);
	if ((*tmp)[1] == NULL)
		ft_context_free_err(data, tmp, 2, "ft_conc_tmp malloc");
}

static void	ft_conc_tmp(t_data *data, char ***tmp, int aln)
{
	char	*first;
	char	*second;

	ft_arrtostr(data, aln, tmp, &second);
	first = ft_strdup((*tmp)[0]);
	ft_free_arr(*tmp, aln);
	if (first == NULL)
	{
		free(second);
		ft_context_free_err(data, tmp, aln, "ft_conc_tmp malloc");
	}
	*tmp = ft_calloc(3, sizeof(char *));
	if (*tmp == NULL)
	{
		free(first);
		free(second);
		ft_context_free_err(data, tmp, 0, "ft_conc_tmp malloc");
	}
	ft_fill_tmp_rgb(data, tmp, &first, &second);
}

void	ft_parse_rgb(t_data *data, char ***tmp, int *op, int i)
{
	char	**rgb;
	int		num[3];
	int		aln;

	aln = ft_arrlen(*tmp);
	if (aln > 2)
		ft_conc_tmp(data, tmp, aln);
	rgb = ft_split((*tmp)[1], ',');
	if (rgb == NULL || ft_arrlen(rgb) != 3)
	{
		ft_free_arr(rgb, ft_arrlen(rgb));
		ft_context_free_err(data, tmp, aln, "RGB format is wrong");
	}
	while (i < 3)
	{
		num[i] = ft_atoi(rgb[i]);
		if (num[i] > 255 || num[i] < 0)
		{
			ft_free_arr(rgb, 3);
			ft_context_free_err(data, tmp, aln, "RGB must be in 0-255");
		}
		i++;
	}
	*op = (0 << 24 | num[0] << 16 | num[1] << 8 | num[2]);
	ft_free_arr(rgb, 3);
}
