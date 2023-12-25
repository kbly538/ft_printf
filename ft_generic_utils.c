/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:58 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:43:34 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding(char c, int count)
{
	int	counter;
	int	write_res;

	counter = 0;
	if (count <= 0)
		return (0);
	while (count > 0)
	{
		write_res = write(1, &c, 1);
		if (write_res == -1)
			return (-1);
		counter += write_res;
		count--;
	}
	return (counter);
}

int	ft_padding_len(const char *s, t_flags *flags)
{
	int	len;

	if (!s)
		len = 0;
	len = ft_strlen(s);
	if (len >= flags->width && len >= flags->precision)
		return (0);
	else if (flags->width > flags->precision && flags->precision > len)
		return (flags->width - flags->precision);
	else if (flags->precision < len && flags->width > len)
		return (flags->width - len);
	else if (flags->precision >= flags->width)
		return (0);
	else if (len < flags->width)
		return (flags->width - len);
	return (len);
}

int	ft_precision_len(const char *s, t_flags *flags)
{
	int	len;

	if (!s)
		len = 0;
	len = ft_strlen(s);
	if (len >= flags->precision)
		return (0);
	else if (flags->precision > len)
		return (flags->precision - len);
	return (len);
}

int	ft_print_hashed(char c)
{
	int	count;

	count = 0;
	if (c == 'x')
		count += write(1, "0x", 2);
	else if (c == 'X')
		count += write(1, "0X", 2);
	return (count);
}
