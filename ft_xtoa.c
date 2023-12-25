/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:18:46 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:42:06 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xtoa(unsigned int num, char lettercase)
{
	const char		*hexdigits;
	char			*hexstr;
	int				size;
	int				islower;
	unsigned int	tmp;

	hexdigits = "0123456789ABCDEF0123456789abcdef"; 
	islower = (lettercase == 'x') * 16;
	size = 1;
	tmp = num;
	if (num == 0)
		size = 2;
	while (tmp && size++)
		tmp /= 16;
	hexstr = (char *)malloc(sizeof(char) * size);
	if (!hexstr)
		return (NULL);
	hexstr[--size] = '\0';
	while ((num || num + '0' == '0') && size)
	{
		hexstr[--size] = ((char)hexdigits[num % 16 + islower]);
		num /= 16;
	}
	return (hexstr);
}
