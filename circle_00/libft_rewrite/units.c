#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void) 
{
    const char *largestring = "Foo Bar Baz";
    const char *smallstring = "Baz";
    char *ptr;
    char *not_mine;

    ptr = ft_strnstr(largestring, smallstring, 12);
    not_mine = strnstr(largestring, smallstring, 12);
    printf("mine: %s\nnot_mine: %s\n", ptr, not_mine); 

    char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char *empty = (char*)"";

    ptr = ft_strnstr(haystack, "cd", 8);
    not_mine = strnstr(haystack, "cd", 8);
    printf("mine: %s\nnot_mine: %s\n", ptr, not_mine); 
}
