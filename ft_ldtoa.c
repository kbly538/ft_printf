/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:09:34 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:43:21 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isneg(long num)
{
	return (num < 0);
}

int	ft_get_ld_len(long num)
{
	int	length;

	length = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= 10;
		length++;
	}
	return (length);
}

char	*ft_ldtoa(long num)
{
	char	*numstr;
	int		sign;
	int		numlength;
	int		i;

	sign = isneg(num);
	numlength = ft_get_ld_len(num) + sign + 1;
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
