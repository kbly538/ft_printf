/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:38:50 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/18 04:52:04 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//"# +" 
int		ft_processflags(char *fstr, int ix, va_list args)
{
	int	len;
	va_list copyargs;

	va_copy(copyargs, args);
	len = 0;
	if (fstr[ix] == '#' && va_arg(copyargs, long) != 0)
	{
		if (fstr[ix+1] == 'x')
			len += ft_printstring("0x");
		else if (fstr[ix+1] == 'X')
			len += ft_printstring("0X");
	} 
	else if((fstr[ix] == '+' || fstr[ix] == '-') && (fstr[ix + 1] == 'd' || fstr[ix + 1] == 'i'))
	{
		int arg = va_arg(copyargs, int);
		if (arg >= 0)
			len += ft_printchar('+');
	}
	else if(fstr[ix] == ' ' && (fstr[ix + 1] == 'd' || fstr[ix + 1] == 'i'))
	{	
		int arg = va_arg(copyargs, int);
		if (arg >= 0)
			len += ft_printchar(' ');
	}
	va_end(copyargs);

	return (len);
}