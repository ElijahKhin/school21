/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:34:23 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:34:24 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void	rand_init(void)
{
	srand(time(NULL) * getpid());
}

t_real	rt_rand(void)
{
	return (rand() / (float)RAND_MAX);
}

t_real	rt_urand(void)
{
	return ((rand() / (float)RAND_MAX - 0.5) * 2);
}
