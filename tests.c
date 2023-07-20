#include "ft_printf.h"

int main()
{
	char *monstr;
	char *orgstr;
	char  testfor;
	int x;
	int y;
	monstr = "mon:%c\n";
	orgstr = "org:%c\n";

	testfor = 'f';
	x = printf(orgstr, testfor);
	y = ft_printf(monstr, testfor);


	
	// printf("diff: %d\n",  x - y );
	// printf("org:%d\n", x);
	// printf("fak:%d\n", y);
	return (0);
}
