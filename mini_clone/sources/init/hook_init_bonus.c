/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:47 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:55:48 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <mlx.h>
# include <events.h>
# include <minirt.h>

t_bool	hook_init(t_scene *scene)
{
	console_put(MLX_INIT);
	mlx_hook(scene->mlx.win, EXIT_WINDOW, MASK_BUTTON, close_program, scene);
	mlx_hook(scene->mlx.win, KEY_DOWN, MASK_BUTTON, key_handle, scene);
	mlx_mouse_hook(scene->mlx.win, mouse_handle, scene);
	console_put(RT_READY);
	mlx_loop(scene->mlx.ptr);
	return (true);
}

#endif
