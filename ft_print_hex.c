/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:26:46 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/08 21:01:39 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(char lettercase, unsigned int num, t_flags *flags)
{
	t_hex_specs	*specs;
	int			count;

	specs = malloc(sizeof(t_hex_specs));
	if (!specs)
		return (0);
	init_format_hex(specs);
	if (lettercase == 'X')
		specs->lettercase = 'X';
	specs = build_format_hex(num, flags, specs);
	count = print_hex_format(num, flags, specs);
	free(specs);
	return (count);
}
