#include "ft_printf.h"

int main()
{
	//   ft_printf("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1);
	char *monstr;
	char *orgstr;
	int  testfor;
	int x;
	int y;
	monstr = "mon:%+020d\n";
	orgstr = "org:%+020d\n";

	testfor = 42000;
	x = printf(orgstr, testfor);
	y = ft_printf(monstr, testfor);


	
	printf("diff: %d\n",  x - y );
	printf("org:%d\n", x);
	printf("fak:%d\n", y);
	return (0);
}
