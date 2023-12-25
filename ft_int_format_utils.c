/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_format_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:45:53 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 01:49:13 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format_int(t_int_specs *specs)
{
	specs->minus = 0;
	specs->num_len = 0;
	specs->precision_len = 0;
	specs->pad_char = ' ';
	specs->padding = 0;
	specs->plus = 0;
	specs->space = 0;
	specs->zero = 0;
	specs->data = NULL;
	specs->negative = 0;
}

static void	handle_flags(int n, t_flags *flags, t_int_specs *specs)
{
	if (specs->num_len >= flags->width)
	{
		flags->zero = 0;
		specs->zero = 0;
	}
	if (flags->zero && flags->minus)
		flags->zero = 0;
	if (flags->zero && !flags->minus && !(flags->precision > 0))
	{
		specs->zero = 1;
		specs->pad_char = '0';
	}
	if (flags->space && n >= 0 && !flags->plus)
		specs->space = 1;
	if (flags->plus)
		specs->plus = 1;
}

static void	handle_width(int n, t_flags *flags, t_int_specs *specs)
{
	if (flags->width)
	{
		if (flags->width > specs->num_len)
		{
			specs->padding = 
				flags->width - specs->space 
				- (flags->plus || (n < 0)) 
				- (specs->num_len + specs->precision_len); 
		}
	}
}

static void	handle_presicion(t_flags *flags, t_int_specs *specs)
{
	int		exceeds_precision;

	exceeds_precision = specs->num_len > flags->precision;
	if (flags->precision)
	{
		if (exceeds_precision)
			specs->precision_len = 0;
		else if (!exceeds_precision)
			specs->precision_len = flags->precision - specs->num_len;
	}
}

t_int_specs	*build_format_int(int n, t_flags *flags, t_int_specs *specs)
{
	long	num;
	int		raw_num_len;

	num = n;
	init_format_int(specs);
	if (num < 0)
	{
		specs->negative = 1;
		num *= -1;
	}
	specs->data = ft_ldtoa(num);
	if (!specs->data)
	{
		free(specs);
		return (NULL);
	}
	raw_num_len = ft_strlen(specs->data);
	specs->num_len = raw_num_len;
	if (flags->precision == -1 && n == 0)
		specs->num_len = 0;
	handle_flags(n, flags, specs);
	handle_presicion(flags, specs);
	handle_width(n, flags, specs);
	return (specs);
}
