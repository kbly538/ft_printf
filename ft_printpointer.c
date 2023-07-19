/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:26:46 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/18 15:04:34 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(size_t num)
{
	const char		*hexnumslower;
	char			*hexstr;
	int				size;
	size_t			numcpy;
	int				len;

	hexnumslower = "0123456789abcdef"; 
	numcpy = num;
	size = 0;
	if (num == 0)
	{
		ft_printstring("(nil)");
		return (5);
	}
	while (numcpy && ++size)
		numcpy /= 16;
	hexstr = (char *)malloc(sizeof(char) * (size + 1));
	if (!hexstr)
		return (0);
	hexstr[size--] = '\0';
	while (num)
	{
		hexstr[size--] = ((char)hexnumslower[num % 16]);
		num /= 16;
	}
	ft_printstring("0x");
	ft_printstring(hexstr);
	len = ft_strlen(hexstr);
	free(hexstr);
	
	return (len + 2);
}
