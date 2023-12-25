/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:12:45 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:44:24 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptoa(unsigned long num)
{
	const char		*hexdigits;
	char			*hexstr;
	int				size;
	unsigned long	tmp;

	hexdigits = "0123456789abcdef"; 
	size = 1;
	tmp = (unsigned long) num;
	num = (unsigned long) num;
	if (num == 0)
		size = 2;
	while (tmp && size++)
		tmp /= 16;
	hexstr = (char *)malloc(sizeof(char) * size);
	if (!hexstr)
		return (0);
	hexstr[--size] = '\0';
	while (num && size)
	{
		hexstr[--size] = ((char)hexdigits[(unsigned long)num % 16]);
		num /= 16;
	}
	return (hexstr);
}
