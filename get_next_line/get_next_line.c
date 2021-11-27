/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:23:19 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/27 19:53:32 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/fhiedi/desktop/projects/libft/libft.h"

#define BUF_SIZE 10000

char *get_next_line(int fd)
{
	int output;
	static int runner;
	char *ret;
	char buf[BUF_SIZE + 1];
	
	output = read(fd, buf, BUF_SIZE);
	buf[output] = '\0';
	while (buf[runner] != '\n')
		runner++;
	ret = (char *)malloc(sizeof(char) * (runner+1));
	ft_strlcpy(ret, buf, runner);
	ret[runner+1] = '\0';
	return (ret);
}

int main(int argc, char** argv)
{
	int output;
	char *take;
	char buf[BUF_SIZE+1];
	char **take_split;

	output = open(argv[1], O_RDONLY);

	while (take != NULL)
	{
		take = get_next_line(output);
		printf("%s\n", take);
	}
	return (0);
}
