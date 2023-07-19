/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:59:30 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/19 04:19:09 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstring(const char *s)
{
	int result;
	int strlen;

	if (s == NULL)
	{
		result = write(1, "(null)", 6);
		return (6);
	}
	strlen = ft_strlen(s);
	result = write(1, s, strlen);
	if(result >= 0)
		return (strlen);
	else
		return (strlen+1);
	
}
