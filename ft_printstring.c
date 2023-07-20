/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:59:30 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 05:25:13 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstring(const char *s, flagparty_t *flags)
{
	int result;
	int strlen;
	if (s == NULL)
	{
		result = write(1, "(null)", 6);
		return (6);
	} 
	else if (s[0] == '0' && flags->precision != -1)
	{
		strlen = write(1, "0", 1);
		result = 1;
	}
	else if (s[0] == '0' && flags->precision == -1 && flags->width != 0)
		result = write(1, " ", 1);
	else if (s[0] == '0' && flags->precision == -1 && flags->width == 0)
	{
		strlen = 0;
		result = 0;
	}
	else
	{
		strlen = ft_strlen(s);
		result = write(1, s, strlen);
	}
		

	if(result >= 0)
		return (strlen);
	else
		return (strlen+1);
	
}
