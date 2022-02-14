/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:25:09 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/14 19:10:38 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int get_width(char **format)
{
	int width;
	int runner;

	runner = 0;
	width = (format[0][++runner] - 48) * 10;
	while (ft_isdigit(format[0][++runner]))
		width = (width + (format[0][runner] - 48)) * 10;
	return (width/10);
}
