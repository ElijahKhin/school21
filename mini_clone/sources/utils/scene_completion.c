/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_completion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:34:26 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:34:27 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <minirt.h>

void	scene_completion(t_real *completion, t_real add)
{
	if (*completion == 0.0)
		console_putnn("|");
	if (floor(*completion) < floor(*completion + add))
		write(1, "=", 1);
	*completion += add;
	if (floor(*completion) == 50)
		write(1, "|\n", 2);
}
