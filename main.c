#include "./bonus/ft_printf.h"

typedef struct some_struct
{
	int width;
	int len_of_width;
} some;

void test_fun(some *df)
{
	df -> width = 20;
}

int main(void)
{
	some df;

	df.width = 10;
	test_fun(&df);
	printf("%d", df.width);
}
