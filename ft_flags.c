/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:00:26 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 05:11:38 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void printflags(flagparty_t *fs)
{
	printf("	 hash: %d\n", fs->hash);
	printf("	 zero: %d\n", fs->zero);
	printf("	minus: %d\n", fs->minus);
	printf("	 plus: %d\n", fs->plus);
	printf("	space: %d\n", fs->space);
	printf("	width: %d\n", fs->width);
	printf("    precision: %d\n", fs->precision);
}

int ft_getwidth(char *numericstr)
{
	int numlen;
	char *tempnumericstr;
	int widthsize;

	numlen = 0;
	while (ft_isdigit(numericstr[numlen]))
		numlen++;

	tempnumericstr = ft_substr(numericstr, 0, numlen);
	widthsize = ft_atoi(tempnumericstr);
	free(tempnumericstr);
	return (widthsize);
}

int ismodifier(char c)
{
	const char *modifiers = "cspdiuxX%";
	while (*modifiers)
	{
		if (c == *modifiers++)
			return (1);
	}
	return (0);
}

int numlen(int num)
{
	int len;

	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return len;
}
void resetflags(flagparty_t *flags)
{
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
}

int parseflags(char *str, flagparty_t *flags)
{
	char *flagsstr;
	int index;
	int widthsize;

	flagsstr = ft_strdup(str);
	if (!flagsstr)
		return (0);
	index = 0;
	while (!ismodifier(str[index]) && (str[index] != '\0'))
	{

		if (str[index] == '#')
			flags->hash = 1;
		else if (str[index] == '-')
			flags->minus = 1;
		else if (str[index] == '+')
			flags->plus = 1;
		else if (str[index] == ' ')
		{
			flags->space = 1;
		}
		else if (str[index] == '.' && (str[index + 1] == '0' || ismodifier(str[index + 1])))
		{
	
			flags->precision = -1;
		}
		else if (str[index] == '.' && !ismodifier(str[index + 1]) && str[index + 1] != '\0')
		{
			widthsize = ft_getwidth(str + index + 1);
			index += numlen(widthsize);
			flags->precision = widthsize;
		}
		else if (ft_isdigit(str[index]) && str[index] != '0' && flags->width == 0)
		{

			widthsize = ft_getwidth(str + index);
			index += numlen(widthsize) - 1;
			flags->width = widthsize;
		}
		else if (str[index] == '0')
			flags->zero = 1;

		index++;
	}
	free(flagsstr);
	return (index);
}
void fixflags(flagparty_t *flags, char c)
{
	if (flags->precision > 0)
		flags->zero = 0;
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (c != 'x' && c != 'X')
		flags->hash = 0;
	if (flags->precision == -1)
		flags->zero = 0;
}
