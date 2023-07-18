#include "ft_printf.h"

int charcmp(char c)
{
	int orig = printf("   printf: %c\n", c);
	int mine   = ft_printf("ft_printf: %c\n", c);
	return (orig == mine);
}

int decimalcmp(int i)
{
	int orig = printf("   printf:%+.12d\n", i);
	int mine   = ft_printf("ft_printf:%+ d\n", i);
	return (orig == mine);
}



int main()
{
	int y = ft_printf("%+-d\n", 2);
	int x = printf("%+++-d\n", 2);

	return (0);
}
