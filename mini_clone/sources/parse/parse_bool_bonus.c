/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bool_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:26:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:26:52 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_bool(char **line, t_bool *in)
{
	int	num;

	if (!parse_int(line, &num))
		return (false);
	if (num != 0 && num != 1)
		return (error_msg(ERR_TF_CONDITION));
	*in = (t_bool)num;
	return (true);
}
