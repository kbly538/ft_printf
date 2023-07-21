/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:44:52 by anlima            #+#    #+#             */
/*   Updated: 2023/07/21 04:18:10 by kbilgili         ###   ########.fr       */
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

typedef struct t_flagparty
{
	int	hash;
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	width;
	int	precision;
}				t_flagparty;

char	*ft_ptoa(unsigned long num);
int		ft_printchar(char c,t_flagparty *flags);

int			ft_printf(const char	*src, ...);
int			ft_printhex(char c, unsigned int l, t_flagparty *flags);
int			ft_printpointer(unsigned long num, t_flagparty *flags);
int			ft_printint(int i, t_flagparty *flags);
int			ft_printuint(unsigned int i, t_flagparty *flags);
int			ft_printstring(const char *s, t_flagparty *flags);
char		*ft_utoa(unsigned int u);
const char	*ft_handlesubspecifiers(const char *src, va_list copy);
int			ft_digitcountu(unsigned int n);
int			parseflags(char *str, t_flagparty *flags);
void		resetflags(t_flagparty *flags);
int			ft_isflag(char c);
void		fixflags(t_flagparty *flags, char c);
void		printflags(t_flagparty *fs);
int			ft_getldlen(long num);
char		*ft_ldtoa(long num);
int			printpadding(char c, int count);
char		*ft_xtoa(unsigned int num, char lettercase);
int 		ft_paddinglen(const char *var, t_flagparty *flags);
int ft_print_hashed(char c);
int ft_precisionlen(const char *var, t_flagparty *flags);
int handlexzero(t_flagparty *flags);


#endif