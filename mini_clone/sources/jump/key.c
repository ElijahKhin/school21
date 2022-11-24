/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:24:30 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:44:00 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <jump_tables.h>
# include <events.h>
# include <unistd.h>

t_bool	jump_key(t_scene *scene, int key)
{
	int					idx;
	static t_jump_key	jk[] = {
	{Esc, free_and_exit},
	{One, render_flat},
	{Two, render_unlit},
	{Three, render_aabb},
	{Enter, render_scene},
	{Dot, next_cam},
	{Comma, prev_cam},
	{NOKEY, NULL}
	};

	idx = 0;
	while (jk[idx].key != NOKEY && key != jk[idx].key)
		idx += 1;
	if (jk[idx].key == NOKEY)
		return (false);
	return (jk[idx].press(scene));
}

#endif
