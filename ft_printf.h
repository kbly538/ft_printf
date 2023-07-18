/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:44:52 by anlima            #+#    #+#             */
/*   Updated: 2023/07/18 03:27:41 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int			ft_printf(const char	*src, ...);
int			ft_printhex(char c, long l);
int			ft_printpointer(size_t num);
int			ft_printchar(char c);
int			ft_printint(int i);
int			ft_printuint(unsigned int i);
int			ft_printstring(const char *c);
char		*ft_utoa(unsigned int u);
const char	*ft_handlesubspecifiers(const char *src, va_list copy);
int			ft_digitcountu(unsigned int n);
int 		ft_processspec(char *fstr, int ix, va_list args);
int			ft_processflags(char *fstr, int ix, va_list args);

int 		ft_isflag(char c);
#endif