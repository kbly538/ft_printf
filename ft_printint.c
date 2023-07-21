/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:06 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 21:26:10 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handlepadding(long n, t_flagparty *flags)
{
	int	numlen;
	int	paddinglength;
	int	printcount;

	numlen = ft_getldlen(n);
	paddinglength = 0;
	printcount = 0;
	if (flags->plus)
		flags->width--;
	if (flags->width > flags->precision && flags->width > numlen)
	{
		if (numlen > flags->precision)
			paddinglength = flags->width - (n < 0) - numlen;
		else
			paddinglength = flags->width - (n < 0) - flags->precision;
		if (flags->zero && n != 0)
			printcount += printpadding('0', paddinglength);
		else
			printcount += printpadding(' ', paddinglength);
	}
	return (printcount);
}

int	handlepresicion(long n, t_flagparty *flags)
{
	int	numlen;
	int	printcount;

	printcount = 0;
	numlen = ft_getldlen(n);
	if (flags->minus && flags->precision > numlen)
	{
		printcount += printpadding('0', flags->precision - numlen);
	}
	if (!flags->minus && flags->precision > numlen)
	{
		printcount += printpadding('0', flags->precision - numlen);
	}
	return (printcount);
}

int	handlerightjustified(int n, long num, char *numstr, t_flagparty *flags)
{
	int	count;

	count = 0;
	if (flags->space && n >= 0)
		count += write(1, " ", 1);
	if (n < 0 && n != 0 && flags->zero)
		count += write(1, "-", 1);
	if ((flags->width || flags->precision || flags->zero))
		count += handlepadding(num, flags);
	if (flags->plus && n >= 0)
		count += write(1, "+", 1);
	if (n < 0 && n != 0 && !flags->zero)
		count += write(1, "-", 1);
	if (flags->precision != -1)
		count += handlepresicion(num, flags);
	count += write(1, numstr, ft_strlen(numstr));
	return (count);
}

int	ft_printint(int n, t_flagparty *flags)
{
	int		printlen;
	long	num;
	char	*numstr;

	printlen = 0;
	num = n;
	if (n < 0)
	{
		num *= -1;
		flags->width--;
	}
	numstr = ft_ldtoa(num);
	if (num == 0 && flags->precision == -1)
	{
		printlen += printpadding(' ', flags->width);
		printlen += write(1, "", 0);
	}
	else if (flags->minus)
	{
		if (n < 0)
			printlen += write(1, "-", 1);
		printlen += handlepresicion(num, flags);
		printlen += write(1, numstr, ft_strlen(numstr));
		if ((flags->width || flags->precision || flags->zero))
			printlen += handlepadding(num, flags);
	}
	else
		printlen += handlerightjustified(n, num, numstr, flags);
	free(numstr);
	return (printlen);
}
