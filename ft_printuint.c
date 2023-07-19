/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:00:29 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/18 15:04:32 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printuint(unsigned int n)
{
	char	*numstr;
	unsigned int	len;

	numstr = ft_utoa(n);
	len = ft_printstring(numstr);
	free(numstr);
	return (len);
}