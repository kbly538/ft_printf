/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_format_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:33:41 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/08 21:01:39 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format_hex(t_hex_specs *specs)
{
	specs->hash = 0;
	specs->lettercase = 'x';
	specs->num_len = 0;
	specs->precision_len = 0;
	specs->pad_char = ' ';
	specs->padding = 0;
	specs->plus = 0;
	specs->space = 0;
	specs->zero = 0;
	specs->data = NULL;
}

static void	handle_flags(t_flags *flags, t_hex_specs *specs)
{
	if (flags->hash)
		specs->hash = 2;
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

static void	handle_width(t_flags *flags, t_hex_specs *specs)
{
	if (flags->width)
	{
		if (flags->width > specs->num_len)
		{
			specs->padding = 
				flags->width - specs->space - flags->plus 
				- (specs->num_len + specs->precision_len)
				- specs->hash;
		}
	}
}

static void	handle_presicion(t_flags *flags, t_hex_specs *specs)
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

t_hex_specs	*build_format_hex(unsigned int n, t_flags *f, t_hex_specs *s)
{
	int		raw_num_len;

	s->data = ft_xtoa(n, s->lettercase);
	if (!s->data)
		return (NULL);
	raw_num_len = ft_strlen(s->data);
	s->num_len = raw_num_len;
	if (f->precision == -1 && n == 0)
		s->num_len = 0;
	if (n == 0)
		f->hash = 0;
	handle_flags(f, s);
	handle_presicion(f, s);
	handle_width(f, s);
	return (s);
}
