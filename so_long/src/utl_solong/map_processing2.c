/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:27:08 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/26 16:43:54 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_rectangular(t_map_data *map_data)
{
	int runner;
	int standard_len;

	runner = 0;
	standard_len = lb_strlen(map_data->splited_map[runner++]);
	while(map_data->splited_map[runner])
	{
		if (lb_strlen(map_data->splited_map[runner++]) != standard_len)
		{
			ft_printf("ERROR: Map isn't rectangular\n");
			exit(1);
		}
	}
	ft_printf("Map Is RECTANGULAR!\n");
}
