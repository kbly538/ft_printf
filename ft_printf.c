/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:55:42 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/18 04:51:19 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	processformat(char *fstr, va_list args)
{
	int	len;
	int	ix;

	len = 0;
	ix = 0;
		
	while (fstr[ix])
	{	
		
		if(fstr[ix] == '%' && fstr[ix + 1] != '\0')
		{	
			if (ft_isflag(fstr[ix + 1]))
			{
				if (fstr[ix + 1] == ' ')
				{
					while(fstr[ix + 2] == ' ')
						ix++;
				} 
				else if (fstr[ix + 1] == '+')
				{
					while(fstr[ix + 2] == '+' || fstr[ix + 2] == '-')
						ix++;
				}
				len += ft_processflags(fstr, ++ix, args);
			}
			len += ft_processspec(fstr, ++ix, args);
		}
		else
			len += ft_printchar(fstr[ix]);
		ix++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char *fstr;
	int len;

	
	len = 0;
	fstr = ft_strdup(format);
	if (!fstr || *fstr == '\0')
		return (0);
	va_start(args, format);
	len = processformat(fstr, args);	
	va_end(args);
	free(fstr);
	return (len);
}
