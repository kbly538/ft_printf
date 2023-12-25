/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:33:55 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 02:34:08 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_pre_sign(int num, t_hex_specs *specs)
{
	int	count;

	count = 0;
	if (specs->hash && specs->lettercase == 'x')
		count += write(1, "0x", 2);
	else if (specs->hash && specs->lettercase == 'X')
		count += write(1, "0X", 2);
	else if (specs->space && num >= 0)
		count += write(1, " ", 1);
	else if (specs->plus && num >= 0)
		count += write(1, "+", 1);
	if (specs->plus && num < 0)
		count += write(1, "0", 1);
	return (count);
}

static int	print_aligned_left_hex(int num, t_hex_specs *specs)
{
	int	count;

	count = 0;
	if (specs->hash && specs->lettercase == 'x')
		count += write(1, "0x", 2);
	else if (specs->hash && specs->lettercase == 'X')
		count += write(1, "0X", 2);
	else if (specs->space && num >= 0)
		count += write(1, " ", 1);
	else if (specs->plus && num >= 0)
		count += write(1, "+", 1);
	if (specs->precision_len)
		count += print_padding('0', specs->precision_len);
	count += write(1, specs->data, specs->num_len);
	if (specs->padding)
		count += print_padding(specs->pad_char, specs->padding);
	return (count);
}

int static	handle_not_zero(int num, t_hex_specs *specs)
{
	int	count;

	count = 0;
	if (!specs->zero)
	{
		if (specs->hash && specs->lettercase == 'x' && num != 0)
		{
			count += write(1, "0x", 2);
		}
		else if (specs->hash && specs->lettercase == 'X' && num != 0)
		{
			count += write(1, "0X", 2);
		}
		else if (specs->space && num >= 0)
			count += write(1, " ", 1);
		else if (specs->plus && num >= 0)
			count += write(1, "+", 1);
	}
	return (count);
}

static int	print_aligned_right_hex(int num, t_hex_specs *specs)
{
	int	count;

	count = 0;
	if (specs->zero)
		count += handle_pre_sign(num, specs);
	if (specs->padding)
		count += print_padding(specs->pad_char, specs->padding);
	count += handle_not_zero(num, specs);
	if (specs->precision_len)
		count += print_padding('0', specs->precision_len);
	count += write(1, specs->data, specs->num_len);
	return (count);
}

int	print_hex_format(unsigned int num, t_flags *flags, t_hex_specs *specs)
{
	int	count;

	count = 0;
	if (flags->minus)
		count += print_aligned_left_hex(num, specs);
	else
		count += print_aligned_right_hex(num, specs);
	free(specs->data);
	return (count);
}
