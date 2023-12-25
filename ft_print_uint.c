/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:00:29 by kbilgili          #+#    #+#             */
/*   Updated: 2023/08/08 21:01:39 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n, t_flags *flags)
{
	t_int_specs	*specs;
	int			count;

	specs = malloc(sizeof(t_int_specs));
	if (!specs)
		return (0);
	specs = build_format_uint(n, flags, specs);
	count = print_uint_format(n, flags, specs);
	free(specs);
	return (count);
}
