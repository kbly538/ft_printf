/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:15:30 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/14 16:53:35 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_flags *flags)
{
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
}

void	fix_flags(t_flags *flags, char c)
{
	if (flags->precision > 0 && c != 's' && c != '%')
		flags->zero = 0;
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (c != 'x' && c != 'X')
		flags->hash = 0;
	if (flags->precision == -1)
		flags->zero = 0;
}

int	ismodifier(char c)
{
	const char	*modifiers;

	modifiers = "cspdiuxX%";
	while (*modifiers)
	{
		if (c == *modifiers++)
			return (1);
	}
	return (0);
}

int	isspec(char c)
{
	const char	*specs;

	specs = ".+- #0123456789";
	while (*specs)
	{
		if (c == *specs++)
			return (1);
	}
	return (0);
}
