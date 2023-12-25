/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:26:46 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:09:24 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_null_zero(int *printlen, t_flags *flags)
{
	if (flags->minus)
	{
		if (flags->precision != -1)
		{
			*printlen += write(1, "0x0", 3);
			*printlen += print_padding(' ', flags->width - 3);
		}
		else
		{
			*printlen += write(1, "0x", 2);
			*printlen += print_padding(' ', flags->width - 2);
		}
		return ;
	}
	if (flags->precision != -1)
	{
		*printlen += print_padding(' ', flags->width - 3);
		*printlen += write(1, "0x0", 3);
	}
	else
	{
		*printlen += print_padding(' ', flags->width - 2);
		*printlen += write(1, "0x", 2);
	}
}

static void	print_right_align(int *printlen, t_flags *flags, char *hexstring)
{
	if (flags->zero)
		*printlen += 
			print_padding('0', ft_padding_len(hexstring, flags) - 2);
	else
		*printlen += 
			print_padding(' ', ft_padding_len(hexstring, flags) - 2);
	*printlen += ft_print_hashed('x');
	if (flags->precision)
		*printlen += print_padding('0', ft_precision_len(hexstring, flags));
	*printlen += write(1, hexstring, ft_strlen(hexstring));
}

int	ft_print_pointer(unsigned long int num, t_flags *flags)
{
	char	*hexstring;
	int		printlen;

	printlen = 0;
	hexstring = ft_ptoa(num);
	if (!hexstring)
		return (-1);
	if (num == 0 || num == (unsigned long) NULL)
	{
		handle_null_zero(&printlen, flags);
		free(hexstring);
		return (printlen);
	}
	if (flags->minus && !flags->zero)
	{
		printlen += ft_print_hashed('x');
		if (flags->precision)
			printlen += print_padding('0', ft_precision_len(hexstring, flags));
		printlen += write(1, hexstring, ft_strlen(hexstring));
		printlen += print_padding(' ', ft_padding_len(hexstring, flags) - 2);
	}
	else if (!flags->minus)
		print_right_align(&printlen, flags, hexstring);
	free(hexstring);
	return (printlen);
}
