/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:58 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/18 03:27:27 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_digitcountint(int n)
{
	unsigned int	i;

	i = 1;
	while (n / 10 > 0 && i++)
		n = n / 10;
	return (i);
}

int	ft_digitcountu(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (n / 10 > 0 && i++)
		n = n / 10;
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	int				nlength;
	char			*numstr;
	unsigned int	size;

	nlength = ft_digitcountu(n);
	size = nlength + 1;
	numstr = malloc(sizeof(char) * size);
	if (!numstr)
		return (NULL);
	numstr[nlength] = '\0';
	while (nlength-- > 0)
	{
		numstr[nlength] = (n % 10) + '0' ;
		n /= 10;
	}
	return (numstr);
}

int	ft_isflag(char c)
{
	return (c == ' ' || c == '+' || c == '#');
}