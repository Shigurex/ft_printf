/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:44:20 by yahokari          #+#    #+#             */
/*   Updated: 2023/01/21 17:11:23 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	init_flags(t_flags *flags)
{
	flags->minus = false;
	flags->zero = false;
	flags->sharp = false;
	flags->space = false;
	flags->plus = false;
	flags->dot = false;
	flags->width = 0;
	flags->precision = 0;
}

void	check_width(t_vars *vars, t_flags *flags)
{
	flags->width = ft_atoi(vars->str);
	while (ft_isdigit(*vars->str))
		vars->str++;
}

void	check_precision(t_vars *vars, t_flags *flags)
{
	flags->dot = true;
	vars->str++;
	flags->precision = ft_atoi(vars->str);
	while (ft_isdigit(*vars->str))
		vars->str++;
}

void	check_flags(t_vars *vars, t_flags *flags)
{
	while (ft_isdigit(*vars->str) || ft_isflag(*vars->str))
	{
		if (*vars->str == '-')
			flags->minus = true;
		else if (*vars->str == '0')
			flags->zero = true;
		else if (*vars->str == '.')
		{
			check_precision(vars, flags);
			continue ;
		}
		else if (*vars->str == '#')
			flags->sharp = true;
		else if (*vars->str == ' ')
			flags->space = true;
		else if (*vars->str == '+')
			flags->plus = true;
		else
		{
			check_width(vars, flags);
			continue ;
		}
		vars->str++;
	}
}

void	check_conversions(t_vars *vars, t_flags *flags)
{
	if (*vars->str == 'c')
		handle_c(vars, flags, va_arg(vars->ap, int));
	else if (*vars->str == 's')
		handle_s(vars, flags, va_arg(vars->ap, char *));
	else if (*vars->str == 'p')
		;
	else if (*vars->str == 'd' || *vars->str == 'i')
		;
	else if (*vars->str == 'u')
		;
	else if (*vars->str == 'x')
		;
	else if (*vars->str == 'X')
		;
	else if (*vars->str == '%')
		;
	vars->str++;
}

void	handle_conversions(t_vars *vars)
{
	t_flags	flags;

	vars->str++;
	init_flags(&flags);
	check_flags(vars, &flags);
	check_conversions(vars, &flags);
}
