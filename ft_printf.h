/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:44:52 by anlima            #+#    #+#             */
/*   Updated: 2023/12/25 04:14:22 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	hash;
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	width;
	int	precision;
}				t_flags;

typedef struct s_int_specs
{
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		padding;
	int		precision_len;
	int		num_len;
	int		pad_char;
	char	*data;
	int		negative;
}				t_int_specs;

typedef struct s_hex_specs
{
	int		hash;
	char	lettercase;
	int		zero;
	int		plus;
	int		space;
	int		padding;
	int		precision_len;
	int		num_len;
	int		pad_char;
	char	*data;
}				t_hex_specs;

char		*ft_ptoa(unsigned long num);
int			ft_print_char(char c, t_flags *flags);
int			ft_printf(const char	*src, ...);
int			ft_print_pointer(unsigned long int num, t_flags *flags);
int			ft_print_string(char *s, t_flags *flags);
int			ft_print_percent(int c, t_flags *flags);
int			ft_print_hashed(char c);
const char	*ft_handlesubspecifiers(const char *src, va_list copy);
int			parse_flags(char *str, t_flags *flags);
void		reset_flags(t_flags *flags);
int			ft_get_ld_len(long num);
void		fix_flags(t_flags *flags, char c);
void		print_flags(t_flags *fs);
char		*ft_ldtoa(long num);
int			print_padding(char c, int count);
char		*ft_xtoa(unsigned int num, char lettercase);
int			ft_padding_len(const char *var, t_flags *flags);
int			ft_precision_len(const char *var, t_flags *flags);
int			ft_print_int(int i, t_flags *flags);
void		init_format_int(t_int_specs *specs);
int			print_int_format(int n, t_flags *f, t_int_specs *s);
t_int_specs	*build_format_int(int n, t_flags *flags, t_int_specs *spec);
int			ft_print_uint(unsigned int i, t_flags *flags);
void		init_format_uint(t_int_specs *specs);
int			print_uint_format(unsigned int n, t_flags *f, t_int_specs *s);
t_int_specs	*build_format_uint(unsigned int n, t_flags *f, t_int_specs *s);
int			ft_print_hex(char c, unsigned int l, t_flags *flags);
void		init_format_hex(t_hex_specs *specs);
int			print_hex_format(unsigned int n, t_flags *f, t_hex_specs *s);
t_hex_specs	*build_format_hex(unsigned int n, t_flags *f, t_hex_specs *s);
int			process_format_str(char *str, int *i, va_list args, t_flags *f);
int			process(char *str, va_list args, int *index, t_flags *flags);
int			ismodifier(char c);
int			isspec(char c);

#endif