/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:59:30 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 21:26:10 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printchar(char c,t_flagparty *flags)
{
	int result;
	
	result = 0;
	if(flags->width && !flags->minus)
	{
		result += printpadding(' ', flags->width - 1);
	} 
	result += write(1, &c, 1);
	if (flags->width && flags->minus)
	{
		result += printpadding(' ', flags->width - 1);
	}
	if(result >= 0)
		return (result);
	else
		return (-1);
}
