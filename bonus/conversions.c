/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:44:20 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/03 13:31:11 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	check_conversions(t_vars *vars, t_flags *flags)
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