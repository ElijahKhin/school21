/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:26:19 by fhiedi            #+#    #+#             */
/*   Updated: 2022/03/09 16:03:25 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../ft_printf.h"
# include "../libft/libft.h"

void	check_flags(char *format, t_arginfo *arginfo)
{
	int runner;

	arginfo -> width = get_width(format);
	runner = arginfo -> width;
	if (format[0] == '-')
	{
		arginfo -> width += 1;
//		arginfo -> printed += 1;
	}
}
