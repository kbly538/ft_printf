/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:59:30 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 02:44:08 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_string(char *s, t_flags *flags)
{
	int	count;
	int	i;
	int	precision_cpy;

	count = 0;
	i = 0;
	precision_cpy = flags->precision;
	if (flags->precision)
	{
		while (s[i] != '\0' && precision_cpy > 0)
		{
			count += write(1, &s[i], 1);
			precision_cpy--;
			i++;
		}
		return (count);
	}
	while (s[i] != '\0')
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

int	handle_right_justified_string(char *s, t_flags *flags)
{
	int	count;
	int	len_with_precision;

	count = 0;
	len_with_precision = 0;
	if (flags->precision > (int)ft_strlen(s) || !flags->precision)
		len_with_precision = ft_strlen(s);
	else if (flags->precision)
		len_with_precision = flags->precision;
	else
		s = "";
	if (len_with_precision < 0)
		len_with_precision = 0;
	if (flags->zero)
		count += print_padding('0', flags->width - len_with_precision);
	else 
		count += print_padding(' ', flags->width - len_with_precision);
	count += write_string(s, flags);
	return (count);
}

int	ft_print_string(char *s, t_flags *flags)
{
	int	printlen;
	int	len_with_precision;

	printlen = 0;
	if (!s)
		s = "(null)";
	len_with_precision = flags->width;
	if (!flags->minus)
		printlen += handle_right_justified_string(s, flags);
	else if (flags->minus)
	{
		printlen += write_string(s, flags);
		len_with_precision = flags->width;
		if (flags->precision > (int)ft_strlen(s) || !flags->precision)
		{
			len_with_precision = flags->width - ft_strlen(s);
		}
		else if (flags->precision > 0)
		{
			len_with_precision = flags->width - flags->precision;
		}
		printlen += print_padding(' ', len_with_precision);
	}
	return (printlen);
}
