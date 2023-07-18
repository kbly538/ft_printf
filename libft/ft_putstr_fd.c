/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:11:24 by kbilgili          #+#    #+#             */
/*   Updated: 2023/07/10 17:09:45 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(s);
	while (size > i)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
