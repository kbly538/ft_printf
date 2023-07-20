/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processspec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:55:42 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 00:08:42 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int ft_processspec(char *fstr, int ix, va_list args)
// {
// 	int len;

// 	len = 0;
// 	if (fstr[ix] == 'c')
// 		len += ft_printchar(va_arg(args, int));
// 	else if (fstr[ix] == 'd' || fstr[ix] == 'i')
// 		len += ft_printint(va_arg(args, int));
// 	else if (fstr[ix] == 'x' || fstr[ix] == 'X')
// 		len += ft_printhex(fstr[ix], va_arg(args, long));
// 	else if (fstr[ix] == '%')
// 		len += ft_printchar('%');
// 	else if (fstr[ix] == 'p')
// 		len += ft_printpointer(va_arg(args, size_t));
// 	else if	(fstr[ix] == 'u')
// 		len += ft_printuint(va_arg(args, unsigned int));
// 	else if	(fstr[ix] == 's')
// 		len += ft_printstring(va_arg(args, void*));
// 	return (len);
// }
