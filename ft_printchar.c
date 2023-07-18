/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:59:30 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/18 01:27:50 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printchar(char c)
{
	int result;

	result = write(1, &c, 1);
	if(result >= 0)
		return (1);
	else
		return (-1);
}
