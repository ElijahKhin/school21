/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:04:32 by chasimir          #+#    #+#             */
/*   Updated: 2022/03/21 19:07:39 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CAST_H
# define CUB_CAST_H

// raycast.c
void	init_st_rc(t_data *main, t_raycast *raycast);
void	calc(t_raycast *raycast, t_data *main);
int		render(t_data *main);

// init_struct.c
void	init_st_rc2(t_data *main, t_raycast *raycast);
void	init_st_rc(t_data *main, t_raycast *raycast);
void	init_key(t_data *main, t_raycast *raycast);

// open_txt.c
void	init_txt(t_data *main);
void	open_txt(t_data *main, t_textures *txt, char *path);
void	load_txt(t_data *main);

//keyhook.c
int		free_all(void);
int		keypress(int keycode, t_keys *keys);
int		keyrelease(int keycode, t_keys *keys);
void	key_event(t_raycast *raycast, t_keys *keys);

//move.c
void	move_a(t_raycast *raycast);
void	move_s(t_raycast *raycast);
void	move_d(t_raycast *raycast);
void	move_w(t_raycast *raycast);

//rotate.c
void	rotate_l(t_raycast *raycast);
void	rotate_r(t_raycast *raycast);

//draw_and_search_dz.c
void	draw_line(t_raycast *raycast, t_textures *txt, int y, int x);
void	seach_draw_and_txt(t_raycast *raycast);
void	choice_txt(t_raycast *raycast, t_data *main, int x);

#endif
