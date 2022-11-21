/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:16:23 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:16:28 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <events.h>
# include <jump_tables.h>

int	mouse_handle(int button, int u, int v, t_scene *scene)
{
	int		idx;

	idx = 0;
	scene->u = u;
	scene->v = v;
	if (scene->viewport == shaded)
		scene->viewport = flat;
	while (!jump_btn(scene, button, &idx))
		idx += 1;
	if (idx == -1)
		return (1);
	if (update(scene) == false)
		free_and_exit(scene);
	return (1);
}

#endif
