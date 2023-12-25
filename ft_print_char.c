/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:59:30 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/08 21:01:39 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, t_flags *flags)
{
	int	result;

	result = 0;
	if (flags->width && !flags->minus)
	{
		result += print_padding(' ', flags->width - 1);
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
