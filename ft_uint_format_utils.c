/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_format_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:57:04 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:42:18 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format_uint(t_int_specs *specs)
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
}

static void	handle_flags(t_flags *flags, t_int_specs *specs)
{
	if (flags->zero && !flags->minus && !(flags->precision > 0))
	{
		specs->zero = 1;
		specs->pad_char = '0';
	}
	if (flags->space && !flags->plus)
		specs->space = 1;
	if (flags->plus)
		specs->plus = 1;
}

static void	handle_width(t_flags *flags, t_int_specs *specs)
{
	if (flags->width)
	{
		if (flags->width > specs->num_len)
		{
			specs->padding = 
				flags->width - specs->space - flags->plus 
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

t_int_specs	*build_format_uint(unsigned int n, t_flags *fl, t_int_specs *sp)
{
	long	num;
	int		raw_num_len;

	num = n;
	init_format_int(sp);
	if (num < 0)
	{
		sp->minus = 1;
		num *= -1;
	}
	sp->data = ft_ldtoa(num);
	if (!sp->data)
		return (NULL);
	raw_num_len = ft_strlen(sp->data);
	sp->num_len = raw_num_len;
	if (fl->precision == -1 && n == 0)
		sp->num_len = 0;
	handle_flags(fl, sp);
	handle_presicion(fl, sp);
	handle_width(fl, sp);
	return (sp);
}
