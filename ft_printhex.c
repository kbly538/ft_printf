/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:26:46 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/21 04:22:40 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(char lettercase, unsigned int num, t_flagparty *flags)
{
	char	*hexstring;
	int		printlen;

	printlen = 0;
	hexstring = ft_xtoa(num, lettercase);
	if (!hexstring)
	{
		free(hexstring);
		return (0);
	}
	if (num == 0)
	{
		printlen += handlexzero(flags);
		free(hexstring);
		return (printlen);
	}
	if (flags->minus && !flags->zero)
	{
		if (flags->hash)
			printlen += ft_print_hashed(lettercase);
		if (flags->precision)
			printlen += printpadding('0', ft_precisionlen(hexstring, flags));
		printlen += write(1, hexstring, ft_strlen(hexstring));
		printlen += printpadding(' ', ft_paddinglen(hexstring, flags) - flags->hash);
	}
	else if (!flags->minus)
	{
		if (flags->hash)
			printlen += ft_print_hashed(lettercase);
		if (flags->zero)
			printlen += printpadding('0', ft_paddinglen(hexstring, flags) - flags->hash);
		else
			printlen += printpadding(' ', ft_paddinglen(hexstring, flags) - flags->hash);
		if (flags->precision )
			printlen += printpadding('0', ft_precisionlen(hexstring, flags));
		printlen += write(1, hexstring, ft_strlen(hexstring));
	}
	free(hexstring);
	return (printlen);
}
