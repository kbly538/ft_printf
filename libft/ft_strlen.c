/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:34:37 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/20 15:27:02 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;
	int		i;

	if (s == NULL)
		return (0);
	len = 0;
	i = 0;
	while (s[i])
	{
		i++;
		len++;
	}
	return (len);
}
