/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:43:20 by scoach            #+#    #+#             */
/*   Updated: 2022/03/22 18:26:21 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**ft_free_arr(char **arr, int ln)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (i < ln)
		{
			if (arr[i] != NULL)
			{
				ft_bzero(arr[i], ft_strlen(arr[i]));
				free(arr[i]);
			}
			i++;
		}
		ft_bzero(arr, sizeof(char *));
		free(arr);
	}
	return (NULL);
}

void	free_txtr(t_data *main)
{
	if (main->west)
		free(main->west);
	if (main->east)
		free(main->east);
	if (main->north)
		free(main->north);
	if (main->south)
		free(main->south);
}

void	free_all_raycast(t_raycast *raycast)
{
	if (raycast)
	{
		if (raycast->keys)
			free(raycast->keys);
		if (raycast->mlx)
		{
			if (raycast->pixel && raycast->pixel->img)
				mlx_destroy_image(raycast->mlx, raycast->pixel->img);
			if (raycast->win)
				mlx_destroy_window(raycast->mlx, raycast->win);
		}
		if (raycast->pixel)
			free(raycast->pixel);
		if (raycast->mlx)
			free(raycast->mlx);
		if (raycast)
			free(raycast);
	}
}

void	ft_free_data(t_data *data)
{
	int	i;

	if (data != NULL)
	{
		if (data->map != NULL)
			ft_free_arr(data->map, ft_arrlen(data->map));
		i = 0;
		while (i < 4)
		{
			if (data->nswe[i] != NULL)
				free(data->nswe[i]);
			i++;
		}
		ft_bzero(data->nswe, sizeof(char *) * 4);
		if (data->gnln != NULL)
		{
			if (*data->gnln != NULL)
				free(*data->gnln);
			free(data->gnln);
		}
		free_txtr(data);
		free_all_raycast(data->raycast);
		ft_bzero(data, sizeof(t_data));
		free(data);
	}
}

void	ft_context_free_err(t_data *data, char ***tmp, int aln, char *msg)
{
	ft_free_arr(*tmp, aln);
	free(tmp);
	ft_error(data, msg, 0);
}
