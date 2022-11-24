/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:24:42 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:45:32 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <jump_tables.h>
# include <parse.h>
# include <libft.h>
# include <error.h>

t_bool	jump_parse(t_scene *scene, char **line)
{
	char				*id;
	int					idx;
	static t_jump_parse	ps[] = {
	{"R", parse_resolution}, {"A", parse_ambience}, {"AA", parse_aa},
	{"SKY", parse_skybox}, {"c", parse_camera}, {"l", parse_light},
	{"lp", parse_light_parallel}, {"sp", parse_sphere}, {"pl", parse_plane},
	{"sq", parse_square}, {"cy", parse_cylinder}, {"tr", parse_triangle},
	{"cyc", parse_cylinder_cap}, {"ds", parse_disk}, {"BRDF", parse_brdf},
	{"cb", parse_cube}, {"py", parse_pyramid}, {"SUN", parse_sun},
	{"obj", parse_wfobj}, {"THREADS", parse_threads},
	{"VP", parse_viewport},
	{NULL, NULL}
	};

	idx = 0;
	id = parse_id(line);
	if (!id)
		return (true);
	while (ps[idx].id && !ft_match(id, ps[idx].id))
		idx += 1;
	free(id);
	if (!ps[idx].id)
		return (error_msg(ERR_PAR_NOID));
	return (ps[idx].parse(scene, line));
}

#endif
