/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:26:46 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/21 04:44:17 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printpointer(unsigned long int num, t_flagparty *flags)
{
	char	*hexstring;
	int		printlen;

	printlen = 0;
	hexstring = ft_ptoa(num);

	if (num == 0)
	{
		if (flags->minus)
		{
			printlen += write(1, "(nil)", 5);
			printlen += printpadding(' ', flags->width - 5);
		}
		else
		{
			printlen += printpadding(' ', flags->width - 5);
			printlen += write(1, "(nil)", 5);
		}			
		free(hexstring);
		return (printlen);
	}
	if (flags->minus && !flags->zero)
	{
		printlen += ft_print_hashed('x');
		if (flags->precision)
			printlen += printpadding('0', ft_precisionlen(hexstring, flags));
		printlen += write(1, hexstring, ft_strlen(hexstring));
		printlen += printpadding(' ', ft_paddinglen(hexstring, flags) - 2);
	}
	else if (!flags->minus)
	{

		
		if (flags->zero)
			printlen += printpadding('0', ft_paddinglen(hexstring, flags) - 2);
		else
			printlen += printpadding(' ', ft_paddinglen(hexstring, flags) - 2);
		printlen += ft_print_hashed('x');
		if (flags->precision )
			printlen += printpadding('0', ft_precisionlen(hexstring, flags));
		printlen += write(1, hexstring, ft_strlen(hexstring));
	}
	free(hexstring);
	return (printlen);
}
