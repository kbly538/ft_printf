/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:55:42 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/21 04:21:03 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parseformat(const char *s, t_flagparty *flags, va_list args)
{
	char	*str;
	int		index;
	int		totallength;

	if (s == NULL)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	index = 0;
	totallength = 0;
	while (str[index] != '\0')
	{
		if (str[index] != '%')
		{
			totallength += write(1, &str[index], 1);
		}
		else
		{
			index++;
			index += parseflags(str + index, flags);
			fixflags(flags, str[index]);
			if (str[index] == 'd' || str[index] == 'i')
			{
				int tmparg = va_arg(args, int);
				totallength += ft_printint(tmparg, flags);
			}
			else if (str[index] == 'c')
			{
				int tmparg = va_arg(args, int);
				totallength += ft_printchar(tmparg, flags);
			}
			else if (str[index] == 's')
			{
				char *tmparg = va_arg(args, char *);
				totallength += ft_printstring(tmparg, flags);
			}
			else if (str[index] == 'x' || str[index] == 'X')
			{
				unsigned int tmparg = va_arg(args, unsigned int);
				totallength += ft_printhex(str[index], tmparg, flags);
			}
			else if (str[index] == 'p')
			{
				totallength += ft_printpointer((unsigned long int)va_arg(args, void*), flags);
			}
		}
		index++;
		resetflags(flags);
	}
	free(str);
	return (totallength);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_flagparty	*flags;
	int			len;

	va_start(args, format);
	flags = malloc(sizeof(t_flagparty));
	if (!flags)
		return (0);
	resetflags(flags);
	len = parseformat(format, flags, args);
	va_end(args);
	free(flags);
	return (len);
}
