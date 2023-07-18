/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:06 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/18 01:31:05 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int n)
{
	int len;
	char *str;
	
	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_printstring(str);
	free(str);
	return (len);
}
