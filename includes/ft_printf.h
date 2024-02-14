/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:28:08 by yahokari          #+#    #+#             */
/*   Updated: 2024/02/14 22:23:52 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

# define UNSET -1

# define ALT_HEX_LOWER "0x"
# define ALT_HEX_UPPER "0X"

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

typedef enum e_type
{
	SENTINEL,
	CONVERSION,
	SPECIFICATION,
	NORMAL_STRING
}	t_type;

typedef struct s_flags
{
	bool	alt_form;
	bool	left_justify;
	bool	zero_padding;
	int		plus_sign;
	char	pad_char;
	int		sign_char;
	int		width;
	int		precision;
}	t_flags;

typedef struct s_vars
{
	va_list		ap;
	int			word_count;
	const char	*str;
	bool		is_error;
}	t_vars;

/* ft_printf.c */
int		ft_printf(const char *format, ...);

/* conversions.c */
void	print_conversions(t_vars *vars);

/* conversion_c.c */
void	print_char(t_vars *vars, t_flags *flags, unsigned char c);

/* conversion_s.c */
void	print_str(t_vars *vars, t_flags *flags, char *str);

/* conversion_p.c */
void	print_address(t_vars *vars, t_flags *flags, uintptr_t p);

/* conversion_di.c */
void	print_int(t_vars *vars, t_flags *flags, int n);

/* conversion_u.c */
void	print_uint(t_vars *vars, t_flags *flags, unsigned int n);

/* conversion_x.c */
void	print_uint_hex_lower(t_vars *vars, t_flags *flags, unsigned int n);

/* conversion_large_x.c */
void	print_uint_hex_upper(t_vars *vars, t_flags *flags, unsigned int n);

/* conversion_percent.c */
void	print_percent(t_vars *vars, t_flags *flags);

/* unsigned.c */
int		num_len_in_str(size_t n, char *base);
void	print_unsigned(t_vars *vars, t_flags *flags, size_t n, char *base);

#endif
