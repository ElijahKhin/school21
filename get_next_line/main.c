/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:51:54 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/24 22:29:08 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 1024*2

int main(int argc, char** argv)
{
	int output;
	int ret;
	char buf[BUF_SIZE+1];

	if (argc <= 1)
		return(0);
	output = open(argv[1], O_RDONLY);
	if (output == -1)
		return (0);
	
	ret = read(output, buf, BUF_SIZE);
    if (ret == -1)
		return (0);
	buf[ret] = '\0';
	printf("%s\n", buf);
	printf("%zu", sizeof(argv[1]));
	close(output);
	return (0);
}
