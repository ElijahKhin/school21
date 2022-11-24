/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:13 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:53:14 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	error_exit(char *message)
{
	ft_putstr_fd("\033[1;31mError\033[0m\n", 1);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	exit (EXIT_FAILURE);
}
