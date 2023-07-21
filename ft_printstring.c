/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:59:30 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 21:26:10 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstring(const char *s, t_flagparty *flags)
{
	int result;
	int strlen;

	if (s == NULL)
	{
		return (printpadding(' ', flags->width));
	}
	strlen = ft_strlen(s);
	if (s[0] == '0' && flags->precision != -1)
	{
		strlen = write(1, "0", 1);
		result = 1;
	}
	// else if (s[0] == '0' && flags->precision == -1 && flags->width != 0)
	// 	result = write(1, " ", 1);
	// else if (s[0] == '0' && flags->precision == -1 && flags->width == 0)
	// {
	// 	strlen = 0;
	// 	result = 0;
	// }
	else
	{	
		if (flags->precision == 0)
			strlen = 0;
		else
			strlen = flags->precision;
		if (!flags->minus && strlen < flags->width)
			printpadding(' ', flags->width - strlen);
		result = write(1, s, strlen);
		if (flags->minus && strlen < flags->width)
			printpadding(' ', flags->width - strlen);
	}
		
	if(result >= 0)
		return (strlen);
	else
		return (strlen+1);
	
}
