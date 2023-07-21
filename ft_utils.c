/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:58 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/21 02:46:13 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
int	ft_getldlen(long num)
{
	int length;
	
	length = 0;

	if (!num)
		return (1);
	while (num)
	{
		num /= 10;
		length++;
	}
	return length;
}


int	ft_digitcountint(int n)
{
	unsigned int	i;

	i = 1;
	while (n / 10 > 0 && i++)
		n = n / 10;
	return (i);
}

int	ft_digitcountu(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (n / 10 > 0 && i++)
		n = n / 10;
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	int				nlength;
	char			*numstr;
	unsigned int	size;

	nlength = ft_digitcountu(n);
	size = nlength + 1;
	numstr = malloc(sizeof(char) * size);
	if (!numstr)
		return (NULL);
	numstr[nlength] = '\0';
	while (nlength-- > 0)
	{
		numstr[nlength] = (n % 10) + '0' ;
		n /= 10;
	}
	return (numstr);
}

int	ft_isflag(char c)
{
	return (c == ' ' || c == '+' || c == '#');
}

int printpadding(char c, int count)
{
	int counter;

	counter = 0;
	if (count == 0)
		return (0);
	while (count > 0)
	{

		counter += write(1, &c, 1);
		count--;
	}
	return (counter);
}

int ft_paddinglen(const char *var, t_flagparty *flags)
{
	int	len;


	if (!var)
		len = 0;
	
	len = ft_strlen(var);

	if (len >= flags->width && len >= flags->precision)
		return (0);
	else if (flags->width > flags->precision && flags->precision > len)
		return (flags->width - flags->precision);
	else if (flags->precision < len && flags->width > len)
		return (flags->width - len);
	else if (flags->precision >= flags->width)
		return (0);
	return (len);
}

int ft_precisionlen(const char *var, t_flagparty *flags)
{
	int	len;

	if (!var)
		len = 0;
	len = ft_strlen(var);
	if (len >= flags->precision)
		return (0);
	else if(flags->precision > len)
		return (flags->precision - len);
	return (len);
}

int ft_print_hashed(char c)
{
	int count;

	count = 0;
	if (c == 'x')
		count += write(1, "0x", 2);
	else if (c == 'X')
		count += write(1, "0X", 2);
	return (count);
}

int	handlexzero(t_flagparty *flags)
{
	int	count;

	count = 0;
	if (flags->minus && flags->width && !flags->precision)
	{
		count += write(1, "0", 1);
		count += printpadding(' ', flags->width - 1);
	}
	else if (flags->width && flags->precision == -1)
		count += printpadding(' ', flags->width);
	else if (flags->precision == -1)
		count += write(1, "", 0);
	else if (flags->precision)
		count += printpadding('0', flags->precision);
	else if (flags->precision == 0)
		count += write(1, "0", 1);
	return (count);
}
