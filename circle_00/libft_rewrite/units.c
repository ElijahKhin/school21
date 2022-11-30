#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void) 
{
    char dest3[30];
    dest3[0] = 'b';
    dest3[1] = 'b';
    dest3[2] = 'b';
    dest3[3] = 'b';
    printf("%s %zu\n", dest3, ft_strlen(dest3)); 
	char * src = "AAAAAAAAA";
    printf("not_mine: %zu %d\n", strlcat(dest3, src, 6), !strcmp(dest3, "bAAAA")); 
    
    char dest2[30];
    memset(dest2, 'b', 4);
    printf("%s %zu\n", dest2, strlen(dest2)); 
    printf("mine: %zu %d\n", ft_strlcat(dest2, src, 6), !strcmp(dest2, "bAAAA")); 
    printf("atoi: %d\n", ft_atoi("      -1234"));
}
