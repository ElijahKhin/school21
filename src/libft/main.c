#include "gnl/get_next_line.h"
#include "libft_basic/libft.h"
#include "../printf/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	ft_printf("%s", get_next_line(fd));
	ft_printf("%d", lb_strlen("world\n"));
}

