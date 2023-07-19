#include "ft_printf.h"

int main()
{
	int x;
	int y;
	x = printf("org: %012d\n", (int)-2147483648);
	y = ft_printf("mon: %012d\n", (int)-2147483648);
	
	printf("eq: x: %d y: %d\n", x, y);
	return (0);
}
