/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:09:34 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 02:55:08 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int isneg(long num)
{
	return (num < 0);
}


char	*ft_ldtoa(long num)
{
	char 	*numstr;
	int		sign;
	int		numlength;
	int			i;
	
	sign = isneg(num);
	numlength = ft_getldlen(num) + sign + 1;
	if (num == 0)
		numlength = 2;
	numstr = (char *)ft_calloc(numlength, sizeof(char));
	if (!numstr)
		return (NULL);
	if (sign)
	{
		num *= -1;
		numstr[0] = '-';
	}
	numstr[--numlength] = '\0';
	i = numlength;
	while (i)
	{
		numstr[--i] = (num % 10) + '0';
		num /= 10;
	}
	return (numstr);
}