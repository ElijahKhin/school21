/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:57:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 14:53:18 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "src/libft/libft_basic/libft.h"
# include "src/libft/gnl/get_next_line.h"
# include "src/printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_enemy {
	int		enemy_x;
	int		enemy_y;
	int		num_img;
	int		delay_img;
	int		rotate_sign;
	int		move_left;
	int		move_right;
	int		img_sleep;
	char	*imgs[5];
}	t_enemy;

typedef struct s_map_data {
	void	*mlx;
	void	*win;
	void	*img;
	int		collect;
	int		movement;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	*name;
	char	*path_map;
	char	*map_in_one_line;
	char	**splited_map;
	t_enemy	enemy;
}	t_map_data;	

int		key_hook(int keycode, t_map_data *map_data);
void	fill_map_data(t_map_data *map_data);
void	map_uploading(t_map_data *map_data);
void	check_file_extension(char *file_name);
void	map_processing(t_map_data *map_data);
void	check_rectangular(t_map_data *map_data);
void	check_walls(t_map_data *map_data);
void	check_elements(t_map_data *map_data);
void	print_error(char *error_mes);
void	map_validation(t_map_data *map_data);
int		which_element(char some_char);
int		free_all(t_map_data *map_data);
void	map_rendering(t_map_data *map_data);
void	put_image_to_map(char element,
			int width_px, int height_px, t_map_data *map_data);
void	put_image_floor(t_map_data *map_data, int width_px, int height_px);
void	put_image(t_map_data *map_data,
			int width_px, int height_px, char *img_path);
void	go_right(t_map_data *map_data);
void	go_left(t_map_data *map_data);
void	go_up(t_map_data *map_data);
void	go_down(t_map_data *map_data);
void	utl_collect(t_map_data *map_data);
void	open_exit(t_map_data *map_data);
void	rewrite_string(t_map_data *map_data);
void	defend_gate(t_map_data *map_data);
void	check_enemies_spots(t_map_data *map_data, int x, int y);
void	check_spot_1(t_map_data *map_data, int x, int y);
void	check_spot_2(t_map_data *map_data, int x, int y);
int		add_anime(t_map_data *map_data);
void	rotate_img(t_map_data *map_data);
void	move_enemy(t_map_data *map_data);
void	you_were_born_to_suck(t_map_data *map_data);
void	you_were_born_to_win(t_map_data *map_data);
void	start_game(t_map_data *map_data);

#endif
