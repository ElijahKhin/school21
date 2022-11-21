/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:21:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:21:52 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>
#include <unistd.h>

t_bool	intersect(const t_shapes *shapes, t_hitrecord *rec)
{
	t_shapes	*cur_shape;

	cur_shape = (t_shapes *)shapes;
	if (rec->ray.max == 0)
		return (false);
	rec->aabb_hit = false;
	while (cur_shape != NULL)
	{
		if (aabb_test(rec->ray, cur_shape->volume, &rec->aabb_hit))
			jump_intersect(cur_shape, rec);
		cur_shape = cur_shape->next;
	}
	if (rec->ref)
		return (true);
	return (false);
}
