/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:09:02 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/10 18:58:49 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_forks_init(t_fork *forks, int forks_count)
{
	int	i;

	i = 0;
	while (i < forks_count)
	{
		forks[i].fork_type = i + 1;
		forks[i].is_busy = 0;
		if (pthread_mutex_init(&forks[i].mutex, 0))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_fork_lock(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->is_busy = 1;
	return (0);
}

int	ft_fork_unlock(t_fork *fork)
{
	fork->is_busy = 0;
	pthread_mutex_unlock(&fork->mutex);
	return (0);
}

int	ft_forks_destroy(t_fork *forks, int forks_count)
{
	int	i;

	i = 0;
	while (i < forks_count)
	{
		forks[i].fork_type = i + 1;
		if (pthread_mutex_destroy(&forks[i].mutex))
			return (-1);
	}
	return (0);
}
