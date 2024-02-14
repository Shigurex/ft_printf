/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:01:45 by yahokari          #+#    #+#             */
/*   Updated: 2024/02/14 22:22:10 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->alt_form = false;
	flags->left_justify = false;
	flags->zero_padding = false;
	flags->plus_sign = UNSET;
	flags->sign_char = UNSET;
	flags->pad_char = ' ';
	flags->width = UNSET;
	flags->precision = UNSET;
}

void	handle_flags(t_vars *vars, t_flags *flags)
{
	while (true)
	{
		if (*vars->str == '#')
			flags->alt_form = true;
		else if (*vars->str == '-')
			flags->left_justify = true;
		else if (*vars->str == '+')
			flags->plus_sign = '+';
		else if (*vars->str == ' ' && flags->plus_sign == UNSET)
			flags->plus_sign = ' ';
		else
			break ;
		++vars->str;
	}
	if (*vars->str == '0' && !flags->left_justify)
	{
		flags->pad_char = '0';
		++vars->str;
	}
}

void	handle_width(t_vars *vars, t_flags *flags)
{
	if (ft_isdigit(*vars->str))
	{
		flags->width = 0;
		while (ft_isdigit(*vars->str))
		{
			flags->width = flags->width * 10 + (*vars->str - '0');
			++vars->str;
		}
	}
	else if (*vars->str == '*')
	{
		flags->width = va_arg(vars->ap, int);
		if (flags->width < 0)
			flags->width *= -1;
		++vars->str;
	}
}

void	handle_precision(t_vars *vars, t_flags *flags)
{
	if (*vars->str == '.')
	{
		++vars->str;
		flags->precision = 0;
		if (ft_isdigit(*vars->str))
		{
			while (ft_isdigit(*vars->str))
			{
				flags->precision = flags->precision * 10 + (*vars->str - '0');
				++vars->str;
			}
		}
		else if (*vars->str == '*')
		{
			flags->precision = va_arg(vars->ap, int);
			++vars->str;
		}
		flags->pad_char = ' ';
	}
}

void	print_conversions(t_vars *vars)
{
	t_flags	flags;

	init_flags(&flags);
	handle_flags(vars, &flags);
	handle_width(vars, &flags);
	handle_precision(vars, &flags);
	if (*vars->str == 'c')
		print_char(vars, &flags, va_arg(vars->ap, int));
	else if (*vars->str == 's')
		print_str(vars, &flags, va_arg(vars->ap, char *));
	else if (*vars->str == 'p')
		print_address(vars, &flags, va_arg(vars->ap, uintptr_t));
	else if (*vars->str == 'd' || *vars->str == 'i')
		print_int(vars, &flags, va_arg(vars->ap, int));
	else if (*vars->str == 'u')
		print_uint(vars, &flags, va_arg(vars->ap, unsigned int));
	else if (*vars->str == 'x')
		print_uint_hex_lower(vars, &flags, va_arg(vars->ap, unsigned int));
	else if (*vars->str == 'X')
		print_uint_hex_upper(vars, &flags, va_arg(vars->ap, unsigned int));
	else if (*vars->str == '%')
		print_percent(vars, &flags);
	else
		vars->is_error = true;
}
