/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_set_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:31 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:53:32 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <libft.h>

t_bool	error_set_null(void *set, char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	ft_memset(set, 0, sizeof(set));
	return (false);
}
