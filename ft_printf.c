/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:55:42 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 02:43:03 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int parseformat(const char *s, flagparty_t *flags, va_list args)
{
	char *str;
	int index;
	int totallength;

	str = ft_strdup(s);
	if (!str)
		return (0);
	index = 0;
	totallength = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			index++;
			index += parseflags(str + index, flags);
			fixflags(flags, str[index]);
			
			if (str[index] == 'd' || str[index] == 'i')
			{
				int tmp = va_arg(args, int);
				totallength += ft_printint(tmp, flags);
			}
			resetflags(flags);
		}
		else
			totallength+= ft_printchar(str[index]);
		index++;

	}
	free(str);
	return (totallength);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int len;

	va_start(args, format);
	flagparty_t *flags;
	flags = malloc(sizeof(flagparty_t));
	if (!flags)
		return (0);
	resetflags(flags);
	len = parseformat(format, flags, args);
	va_end(args);
	free(flags);
	return (len);
}
