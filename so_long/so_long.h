/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:57:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/26 16:32:47 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "src/libft/libft_basic/libft.h"
# include "src/libft/gnl/get_next_line.h"
# include "src/printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map_data {
	char	*name;
	char	*path_map;
	char	*map_in_one_line;
	char	**splited_map;
	int		height;
}	t_map_data;	


typedef struct s_enemy {
	int		x_e;
	int		y_e;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_enemy_vars;

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				movement;
	char			**map;
	int				collect;
	t_enemy_vars	e_vars;
}	t_vars;

typedef struct s_vars_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map_vars;

void	map_uploading(t_map_data *map_data);
void	check_file_extension(char *file_name);
void	map_processing(t_map_data *map_data);
void	check_rectangular(t_map_data *map_data);

#endif
