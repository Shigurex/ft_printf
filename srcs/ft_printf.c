/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:28:18 by yahokari          #+#    #+#             */
/*   Updated: 2024/02/14 22:43:51 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_vars(t_vars *vars, const char *format)
{
	vars->str = format;
	vars->word_count = 0;
	vars->is_error = false;
}

static void	handle_str_with_conversions(t_vars *vars)
{
	while (!vars->is_error && *vars->str)
	{
		if (*vars->str == '%')
		{
			++vars->str;
			print_conversions(vars);
		}
		else
		{
			ft_putchar_fd(*vars->str, STDOUT_FILENO);
			vars->word_count++;
		}
		++vars->str;
	}
}

int	ft_printf(const char *format, ...)
{
	t_vars	vars;

	init_vars(&vars, format);
	va_start(vars.ap, format);
	handle_str_with_conversions(&vars);
	va_end(vars.ap);
	return (vars.word_count);
}
