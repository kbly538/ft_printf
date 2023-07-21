/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:23:41 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/21 04:42:56 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*monstr;
	char	*orgstr;
	int		x;
	int		y;
	int 	addr;

	addr = 32;
	monstr = "mon:-->|%-16.p|<-- \n";
	orgstr = "org:-->|%-16.p|<-- \n";	

	x = printf(orgstr, NULL);
	y = ft_printf(monstr, NULL);
	printf("diff: %d\n", x - y);
	printf("org:%d\n", x);
	printf("fak:%d\n", y);
	return (0);
}
