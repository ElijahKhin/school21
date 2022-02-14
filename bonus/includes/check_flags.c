/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:26:19 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/14 19:16:14 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../ft_printf.h"
# include "../libft/libft.h"

int	*check_flags(char *format)
{
	int data_spec[2];
	int runner;
	int width;

	data_spec[0] = 0;
	width = get_width(&format);
	data_spec[1] = num_len(width);
	if (format[0] == '-')
	{
		data_spec[1] += 1;
		while (width-- > 0)
			data_spec[0] += write(1, "1", 1);
	}
	return (&data_spec);
}
