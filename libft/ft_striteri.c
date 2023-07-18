/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:34:53 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/17 14:25:24 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	//int		length;
	int		i;

	//length = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		f(i, (char *)&s[i]);
		i++;
	}
}