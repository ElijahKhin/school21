/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:14:16 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 14:13:26 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	rewrite_string(t_map_data *map_data)
{
	int		width;
	char	*str;
	char	*move;

	width = map_data->width;
	move = ft_itoa(++map_data->movement);
	str = ft_strjoin("Current Move: ", move);
	while (width > 0)
		put_image(map_data, 50 * width--, 0, "src/utl_solong/img/wall.xpm");
	mlx_string_put(map_data->mlx, map_data->win, 5, 10, 0xffffff, str);
	ft_printf("Current Move: %d\n", map_data->movement);
	free(str);
	free(move);
}

void	open_exit(t_map_data *map_data)
{
	int	runner;
	int	notcountn;

	runner = 0;
	notcountn = 0;
	while (map_data->map_in_one_line[runner])
	{
		if (map_data->map_in_one_line[runner] == 'E')
		{
			put_image(map_data, notcountn % map_data->width * 50,
				notcountn / map_data->width * 50,
				"src/utl_solong/img/o_exit.xpm");
		}
		if (map_data->map_in_one_line[runner] != '\n')
			notcountn++;
		runner++;
	}
}

int	free_all(t_map_data *map_data)
{
	free(map_data->path_map);
	free(map_data->map_in_one_line);
	while (*map_data->splited_map)
		free(*map_data->splited_map++);
	mlx_destroy_window(map_data->mlx, map_data->win);
	exit(0);
	return (0);
}

void	print_error(char *error_mes)
{
	ft_printf("%s\n", error_mes);
	exit(1);
}

int	which_element(char some_char)
{
	static int	e;
	static int	c;
	static int	p;

	if (p == 0 && e == 0 && c == 0)
	{
		e = 0;
		c = 0;
		p = 0;
	}
	if (some_char == 'E')
		e++;
	if (some_char == 'C')
		c++;
	if (some_char == 'P')
		p++;
	if (p > 1)
		print_error("ERROR: Too many players, must be one!");
	if (p == 0 || e == 0 || c == 0)
		return (0);
	else
		return (1);
}
