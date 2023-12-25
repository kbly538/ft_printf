/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:55:01 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/08 21:01:39 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_pre_sign(int num, t_int_specs *specs)
{
	int	count;

	count = 0;
	if (specs->minus)
		count += write(1, "-", 1);
	else if (specs->plus && num >= 0)
		count += write(1, "+", 1);
	else if (specs->space && num >= 0)
		count += write(1, " ", 1);
	if (specs->plus && num < 0)
		count += write(1, "0", 1);
	return (count);
}

static int	print_aligned_left_int(int num, t_int_specs *specs)
{
	int	count;

	count = 0;
	if (specs->minus)
		count += write(1, "-", 1);
	else if (specs->plus && num >= 0)
		count += write(1, "+", 1);
	else if (specs->space && num >= 0)
		count += write(1, " ", 1);
	if (specs->precision_len)
		count += print_padding('0', specs->precision_len);
	count += write(1, specs->data, specs->num_len);
	if (specs->padding)
		count += print_padding(specs->pad_char, specs->padding);
	return (count);
}

static int	print_aligned_right_int(int num, t_int_specs *specs)
{
	int	count;

	count = 0;
	if (specs->zero)
		count += handle_pre_sign(num, specs);
	if (specs->padding)
		count += print_padding(specs->pad_char, specs->padding);
	if (!specs->zero)
	{
		if (specs->minus)
			count += write(1, "-", 1);
		else if (specs->plus && num >= 0)
			count += write(1, "+", 1);
		else if (specs->space && num >= 0)
			count += write(1, " ", 1);
	}
	if (specs->precision_len)
		count += print_padding('0', specs->precision_len);
	count += write(1, specs->data, specs->num_len);
	return (count);
}

int	print_uint_format(unsigned int num, t_flags *flags, t_int_specs *specs)
{
	int	count;

	count = 0;
	if (flags->minus)
		count += print_aligned_left_int(num, specs);
	else
		count += print_aligned_right_int(num, specs);
	free(specs->data);
	return (count);
}
