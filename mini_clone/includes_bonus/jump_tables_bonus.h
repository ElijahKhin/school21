/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_tables_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:52:37 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:17:33 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JUMP_TABLES_BONUS_H
# define JUMP_TABLES_BONUS_H
# if IS_BONUS == 1
#  include <alias.h>
#  include <scene.h>

typedef struct s_jump_btn
{
	int			btn;
	t_bool		(*press)(t_scene *scene);
}	t_jump_btn;

typedef struct s_jump_translate
{
	t_shapetype	type;
	t_bool		(*translate)(t_scene *scene);
}	t_jump_translate;

t_bool	jump_btn(t_scene *scene, int btn, int *idx);
t_bool	jump_translate(t_scene *scene);

# endif
#endif
