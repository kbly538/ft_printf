/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:06 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/19 22:29:29 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *handlepadding(char *src, int len, flagparty_t *flags)
{
	char 	*paddingstr;
	char	*joined;


	if (flags->precision != 0)
		flags->zero = 0;
	if (flags->width > len)
	{
		if (flags->zero)
			paddingstr = createpadding('0', (flags->width - len));
		else
			paddingstr = createpadding(' ', (flags->width - len));
		if (flags->minus)
		{
			joined = ft_strjoin(src, paddingstr);
		}
		else
			joined = ft_strjoin(paddingstr, src);
		free(paddingstr);
		free(src);
		return (joined);
	}
	
	return (src);
}

char *handleprecision(char *src, int len, flagparty_t *flags)
{
	char	*paddingstr;
	char	*joined;

	if (len <= flags->precision && (flags->precision - len > 0))
	{
		paddingstr = createpadding('0', flags->precision - len);
		joined = ft_strjoin(paddingstr, src);
		free(paddingstr);
		free(src);
		return (joined);
	}
	return (src);
}

int ft_printint(int n, flagparty_t *flags)
{
	int len;
	char *str;
	char *prec;
	char *padded;

	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);

	prec = handleprecision(str, len, flags);
	len = 0;
	if (flags->space && n >= 0)
	{
		ft_printchar(' ');
		len++;
	}
	if (flags->plus && n >= 0)
	{
		ft_printchar('+');
		len++;
	}
	padded = handlepadding(prec, ft_strlen(prec), flags);
	len += ft_strlen(padded);
	ft_printstring(padded);
	free(padded);

	return (len);
}
