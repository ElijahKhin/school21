/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:33:58 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:33:59 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>

t_real	clamp(t_real in, t_real min, t_real max)
{
	if (in < min)
		return (min);
	if (in > max)
		return (max);
	return (in);
}
