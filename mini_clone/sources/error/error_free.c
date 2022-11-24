/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:17 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:53:18 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <error.h>
#include <stdlib.h>

t_bool	error_free(char *message, void *ptr)
{
	free(ptr);
	return (error_msg(message));
}
