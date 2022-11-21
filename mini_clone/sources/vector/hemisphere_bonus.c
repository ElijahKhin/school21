/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hemisphere_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:35:50 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:51 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <vector.h>

static t_vec3	get_sampled_vec(const t_real rand1, const t_real rand2)
{
	t_vec3		vec;
	t_real		sintheta;
	t_real		phi;

	sintheta = sqrt(1 - rand1 * rand1);
	phi = PI_2 * rand2;
	vec.x = sintheta * cos(phi);
	vec.y = rand1;
	vec.z = sintheta * sin(phi);
	return (vec);
}

t_vec3	vec3_hsphere(t_vec3 normal,
	const t_real rand1,
	const t_real rand2)
{
	t_vec3	local;
	t_vec3	world;
	t_vec3	fw;
	t_vec3	rt;

	local = get_sampled_vec(rand1, rand2);
	vec3_local_coords(normal, &fw, &rt);
	world = (t_vec3){
		local.x * rt.x + local.y * normal.x + local.z * fw.x,
		local.x * rt.y + local.y * normal.y + local.z * fw.y,
		local.x * rt.z + local.y * normal.z + local.z * fw.z};
	return (world);
}
