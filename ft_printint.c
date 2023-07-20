/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:06 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 04:42:27 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handlepadding(long n, flagparty_t *flags)
{
	int	numlen;
	int	paddinglength;
	int	printcount; 

	numlen = ft_getldlen(n);
	paddinglength = 0;
	printcount = 0;
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

int	handlepresicion(long n, flagparty_t *flags)
{
	int	numlen;
	int	printcount;

	printcount = 0;
	numlen = ft_getldlen(n);
	if (flags->minus && flags->precision > numlen)
		printcount += printpadding('0', flags->precision - numlen);
	if (!flags->minus && flags->precision > numlen)
		printcount += printpadding('0', flags->precision - numlen);
	return (printcount);
}

int	handleleftjustified(int n, long num, char *numstr, flagparty_t *flags)
{
	int	count;

	count = 0;
	if (n < 0 && n != 0)
		count += ft_printchar('-');
	count += handlepresicion(num, flags);
	count += ft_printstring(numstr, flags);
	free(numstr);
	if ((flags->width || flags->precision || flags->zero))
		count += handlepadding(num, flags);
	return (count);
}

int	handlerightjustified(int n, long num, char *numstr, flagparty_t *flags)
{
	int	count;

	count = 0;
	if (flags->plus && n >= 0)
	{
		count += ft_printchar('+');
		flags->width--;
	}
	if (flags->space && n >= 0)
		count += ft_printchar(' ');
	if (n < 0 && n != 0 && flags->zero)
		count += ft_printchar('-');
	if ((flags->width || flags->precision || flags->zero))
		count += handlepadding(num, flags);
	if (n < 0 && n != 0 && !flags->zero)
		count += ft_printchar('-');
	if (flags->precision != -1)
		count += handlepresicion(num, flags);
	count += ft_printstring(numstr, flags);
	free(numstr);
	return (count);
}

int	ft_printint(int n, flagparty_t *flags)
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
	if (flags->minus)
		printlen += handleleftjustified(n, num, numstr, flags);
	else
		printlen += handlerightjustified(n, num, numstr, flags);
	return (printlen);
}
