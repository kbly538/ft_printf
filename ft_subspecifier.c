/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subspecifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:10:41 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/19 22:34:22 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*handleflags(const char *src, va_list copy)
{
	if (*src == '#')
	{
		// TODO
		return (src);
	} 
	else if (*src == '+')
	{
		if (va_arg(copy, int) > 0)
		{
			write(1, "+", 2);
		}
	}
	else if (*src == ' ')
	{
		if ((va_arg(copy, int) > 0) && (*(src - 1) != ' '))
		{
			write(1, " ", 2);
		}
	}
	return (src);
}

const char	*ft_handlesubspecifiers(const char *src, va_list copy)
{
	const char	*specifiers;
	int			handledflag;

	specifiers = "cspdiuxX%%";
	handledflag = 0;	
	while(strchr(specifiers, *src) == NULL)
	{
		if (!handledflag)
		{
			src = handleflags(src, copy);
			handledflag = 1;
		}
		src++;
	}
	return src;
}