/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:58 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/19 03:06:38 by kbilgili         ###   ########.fr       */
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

char	*createpadding(char paddingchar, int paddinglength)
{
	char 	*paddingstr;
	int		i;
	
	paddingstr = malloc(sizeof(char) * paddinglength + 1);
	if (!paddingstr)
		return (NULL);
	i = 0;
	while (i < paddinglength)
	{
		paddingstr[i] = paddingchar;
		i++;
	}
	paddingstr[paddinglength] = '\0';
	return (paddingstr);
}