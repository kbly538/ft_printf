/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:30:58 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:09:41 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(int c, t_flags *flags)
{
	int	result;

	result = 0;
	if (flags->width && !flags->minus)
	{
		if (flags->zero)
		{
			result += print_padding('0', flags->width - 1);
		}
		else if (!flags->zero)
		{
			result += print_padding(' ', flags->width - 1);
		}
	}
	result += write(1, &c, 1);
	if (flags->width && flags->minus)
	{
		result += print_padding(' ', flags->width - 1);
	}
	if (result >= 0)
		return (result);
	else
		return (-1);
}
