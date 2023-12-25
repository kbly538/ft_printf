/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:25:17 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 04:42:53 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_format_str(char *str, int *i, va_list args, t_flags *f)
{
	int		printed_len;

	printed_len = 0;
	if (str[*i] != '%')
	{
		printed_len = write(1, &str[*i], 1);
	}
	else 
	{
		if (!ismodifier(str[*i + 1]) && !isspec(str[*i + 1]))
			return (0);
		printed_len += process(str, args, i, f);
	}
	return (printed_len);
}
