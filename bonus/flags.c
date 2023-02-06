/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:27:59 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/03 13:32:54 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	init_flags(t_flags *flags)
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

static int	ft_isflag(int c)
{
	return (c == '-' || c == '0' || c == '#' \
		|| c == ' ' || c == '+' || c == '.');
}

static void	check_width(t_vars *vars, t_flags *flags)
{
	flags->width = ft_atoi(vars->str);
	while (ft_isdigit(*vars->str))
		vars->str++;
}

static void	check_precision(t_vars *vars, t_flags *flags)
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
			check_precision(vars, flags);
		else if (*vars->str == '#')
			flags->sharp = true;
		else if (*vars->str == ' ')
			flags->space = true;
		else if (*vars->str == '+')
			flags->plus = true;
		else
			check_width(vars, flags);
		if (*vars->str == '-' || *vars->str == '0' || *vars->str == '#' \
			|| *vars->str == ' ' || *vars->str == '+')
			vars->str++;
	}
}
