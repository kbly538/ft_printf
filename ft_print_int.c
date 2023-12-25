/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:29:06 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/09 01:49:53 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int num, t_flags *flags)
{
	t_int_specs	*specs;
	t_int_specs	*bspecs;
	int			count;

	bspecs = malloc(sizeof(t_int_specs));
	if (!bspecs)
		return (-1);
	specs = build_format_int(num, flags, bspecs);
	if (!specs)
		return (-1);
	count = print_int_format(num, flags, specs);
	free(specs);
	return (count);
}
