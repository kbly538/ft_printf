/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:26:46 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/18 04:28:12 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(char lettercase, long num)
{
	const char		*hexnumslower;
	const char		*hexnumsupper;
	char			*hexstr;
	int				size;
	long			numcpy;
	int				len;

	hexnumslower = "0123456789abcdef"; 
	hexnumsupper = "0123456789ABCDEF";
	numcpy = num;
	size = 0;
	if (num == 0)
	{
		ft_printchar('0');
		return (1);
	}
	
	while (numcpy && ++size)
		numcpy /= 16;
	
	hexstr = (char *)malloc(sizeof(char) * (size + 1));

	if (!hexstr)
		return (0);
	
	hexstr[size] = '\0';
	while (num)
	{
		if (lettercase == 'x')
			hexstr[--size] = ((char)hexnumslower[num % 16]);
		else
			hexstr[--size] = ((char)hexnumsupper[num % 16]);
		num /= 16;
	}
	len = ft_strlen(hexstr);
	ft_printstring(hexstr);
	free(hexstr);
	
	return (len);
}
