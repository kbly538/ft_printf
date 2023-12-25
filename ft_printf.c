/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:55:42 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:42:48 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process(char *str, va_list args, int *index, t_flags *flags)
{
	int	c;

	(*index)++;
	*index += parse_flags(str + *index, flags);
	c = 0;
	fix_flags(flags, str[*index]);
	if (str[*index] == 'd' || str[*index] == 'i')
		c += ft_print_int(va_arg(args, int), flags);
	else if (str[*index] == 'c')
		c += ft_print_char(va_arg(args, int), flags);
	else if (str[*index] == 's')
		c += ft_print_string(va_arg(args, char *), flags);
	else if (str[*index] == 'x' || str[*index] == 'X')
		c += ft_print_hex(str[*index], va_arg(args, unsigned int), flags);
	else if (str[*index] == 'p')
		c += ft_print_pointer((unsigned long) va_arg(args, void *), flags);
	else if (str[*index] == 's')
		c += ft_print_string(va_arg(args, char *), flags);
	else if (str[*index] == 'u')
		c += ft_print_uint(va_arg(args, unsigned int), flags);
	else if (str[*index] == '%')
		c += ft_print_percent('%', flags);
	return (c);
}

int	parse_format(const char *s, t_flags *flags, va_list args)
{
	char	*str;
	int		index;
	int		totallength;
	int		process_result;

	if (s == NULL)
		return (-1);
	str = ft_strdup(s);
	if (!str)
		return (-1);
	index = 0;
	totallength = 0;
	while (str[index] != '\0')
	{
		process_result = process_format_str(str, &index, args, flags);
		if (process_result == -1)
			return (-1);
		totallength += process_result;
		index++;
		reset_flags(flags);
	}
	free(str);
	return (totallength);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_flags		*flags;
	int			len;

	va_start(args, format);
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	reset_flags(flags);
	len = parse_format(format, flags, args);
	va_end(args);
	free(flags);
	return (len);
}
