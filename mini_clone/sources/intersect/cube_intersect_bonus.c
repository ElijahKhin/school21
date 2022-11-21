/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intersect_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:56:34 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:56:35 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>

t_bool	cube_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_shapes	face;
	t_cube		*cube;
	int			idx;
	t_bool		hit;

	idx = 0;
	cube = catch->shape;
	hit = false;
	while (idx < 6)
	{
		face.shape = (t_square *)&cube->face[idx];
		if (square_intersect(&face, rec))
		{
			hit = true;
			rec->ref = catch;
		}
		idx += 1;
	}
	return (hit);
}

#endif
