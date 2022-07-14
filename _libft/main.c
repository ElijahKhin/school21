#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *dst;
	char *src;
	
	dst = malloc(1);
	
	memmove(dst, src, 3);
	printf("%s", dst);
}
