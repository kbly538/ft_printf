/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:00:26 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 03:44:19 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getwidth(char *numericstr)
{
	int		numlen;
	char	*tempnumericstr;

	numlen = 0;
	while (ft_isdigit(numericstr[numlen]))
		numlen++;
	tempnumericstr = ft_substr(numericstr, 0, numlen);
	return (tempnumericstr);
}

int	numlen(int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	parse_dot_zero(int *index, char *str, t_flags *flags)
{
	char	*numericstr;

	if (str[*index] == '0')
	{
		flags->zero = 1;
		(*index)++;
	}
	if (ft_isdigit(str[*index]) && str[*index] != '0')
	{
		numericstr = ft_getwidth(str + *index);
		*index += ft_strlen(numericstr) - 1;
		flags->width = ft_atoi(numericstr);
		(*index)++;
		free(numericstr);
	}
	if (str[*index] == '.')
	{
		numericstr = ft_getwidth(str + *index + 1);
		*index += ft_strlen(numericstr);
		flags->precision = ft_atoi(numericstr);
		if (flags->precision == 0)
			flags->precision = -1;
		(*index)++;
		free(numericstr);
	}
}

static void	handle_signs(char *str, int index, t_flags *flags)
{
	if (str[index] == '#')
		flags->hash = 2;
	else if (str[index] == '-')
		flags->minus = 1;
	else if (str[index] == '+')
		flags->plus = 1;
	else if (str[index] == ' ')
		flags->space = 1;
}

int	parse_flags(char *str, t_flags *flags)
{
	char	*flagsstr;
	int		index;

	flagsstr = ft_strdup(str);
	if (!flagsstr)
		return (-1);
	index = 0;
	while ((str[index] != '\0') && !(ismodifier(str[index])))
	{
		while (!(ismodifier(str[index])) && str[index] != '.' 
			&& !ft_isdigit(str[index]) && str[index] != '0')
		{
			handle_signs(str, index, flags);
			index++;
		}
		parse_dot_zero(&index, str, flags);
	}
	free(flagsstr);
	return (index);
}
