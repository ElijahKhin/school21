/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiling_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:34:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:34:33 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <alias.h>
# include <math.h>

t_real	set_tiling(const t_real uv, const t_real scale)
{
	t_real		out;

	out = uv;
	if (fabs(out) > 1)
		out = fmod(out, scale) / scale;
	else
	{
		if (scale < 1)
			out = fmod(out / scale, 1);
		else
			out /= scale;
	}
	if (out < 0)
		out = 1 - fabs(out);
	return (out);
}

#endif
