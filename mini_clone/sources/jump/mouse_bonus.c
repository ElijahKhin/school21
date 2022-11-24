/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:24:35 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:44:40 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <jump_tables.h>
# include <events.h>

t_bool	jump_btn(t_scene *scene, int btn, int *idx)
{
	static t_jump_btn	jb[] = {
	{Mouse1, select_shape},
	{Mouse2, sh_deselect},
	{Mouse4, dof_adjust_up},
	{Mouse5, dof_adjust_dn},
	{NOBTN, NULL}
	};

	if (scene->viewport == brdf)
		scene->viewport = flat;
	scene->do_update = false;
	if (jb[*idx].btn == NOBTN)
	{
		*idx = -1;
		return (true);
	}
	if (btn == jb[*idx].btn)
		return (jb[*idx].press(scene));
	return (false);
}

#endif
