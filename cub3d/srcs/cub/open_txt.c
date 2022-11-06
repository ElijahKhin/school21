/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:07:15 by chasimir          #+#    #+#             */
/*   Updated: 2022/03/22 18:29:51 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_txt(t_data *main)
{
	main->north = malloc(sizeof(t_textures));
	main->south = malloc(sizeof(t_textures));
	main->east = malloc(sizeof(t_textures));
	main->west = malloc(sizeof(t_textures));
	if (!main->north || !main->south || !main->west || !main->east)
		ft_error(main, "malloc init_txt", 0);
	load_txt(main);
}

void	open_txt(t_data *main, t_textures *txt, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(main, "Some texture is missing or access is denied\n", 0);
	else if (close(fd) == -1)
		ft_error(main, "close open_txt", 1);
	txt->img_ptr = mlx_xpm_file_to_image(main->raycast->mlx,
			path, &txt->width, &txt->height);
	txt->img_data = mlx_get_data_addr(txt->img_ptr, &txt->bpp,
			&txt->line_len, &txt->endian);
}

void	load_txt(t_data *main)
{
	open_txt(main, main->north, main->nswe[0]);
	open_txt(main, main->south, main->nswe[1]);
	open_txt(main, main->west, main->nswe[2]);
	open_txt(main, main->east, main->nswe[3]);
}
