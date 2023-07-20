/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:44:52 by anlima            #+#    #+#             */
/*   Updated: 2023/07/20 05:21:29 by kbilgili         ###   ########.fr       */
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

typedef struct flagparty_t
{
	int hash;
	int zero;
	int minus;
	int plus;
	int space;
	int width;
	int precision;
}				flagparty_t;


int			ft_printf(const char	*src, ...);
int			ft_printhex(char c, long l);
int			ft_printpointer(size_t num);
int			ft_printchar(char c, flagparty_t *flags);
int			ft_printint(int i, flagparty_t *flags);
int			ft_printuint(unsigned int i);
int		ft_printstring(const char *s, flagparty_t *flags);
char		*ft_utoa(unsigned int u);
const char	*ft_handlesubspecifiers(const char *src, va_list copy);
int			ft_digitcountu(unsigned int n);
int 		ft_processspec(char *fstr, int ix, va_list args);
int			ft_processflags(char *fstr, int ix, va_list args);
int 		parseflags(char *str, flagparty_t *flags);
void 		resetflags(flagparty_t *flags);
int 		ft_isflag(char c);
void 		fixflags(flagparty_t *flags, char c);
void		printflags(flagparty_t *fs);
int			ft_getldlen(long num);
char		*ft_ldtoa(long num);
int			printpadding(char c, int count);


#endif