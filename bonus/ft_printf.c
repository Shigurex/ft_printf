/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:34:53 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/06 15:38:48 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	init_vars(t_vars *vars, const char *format)
{
	vars->str = format;
	vars->word_count = 0;
	vars->list = NULL;
	vars->is_error = false;
}

void	handle_str(t_vars *vars, char *str, size_t start, size_t len)
{
	char	*tmp;

	tmp = substr_size_t(str, start, len);
	if (!tmp)
	{
		vars->is_error = true;
		return ;
	}
	vars->word_count += ft_strlen(tmp);
	insert_list(&vars->list, tmp, NORMAL_STRING);
}

void	handle_str_with_conversions(t_vars *vars)
{
	const char	*str_start;
	size_t		str_len;

	str_len = 0;
	str_start = vars->str;
	while (!vars->is_error)
	{
		if (!*vars->str || *vars->str == '%')
		{
			handle_str(vars, (char *)str_start, 0, str_len);
			str_len = 0;
		}
		if (vars->is_error || !*vars->str)
			break ;
		if (*vars->str == '%')
		{
			handle_conversions(vars);
			str_start = vars->str;
		}
		else
		{
			str_len++;
			vars->str++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	t_vars	vars;

	init_vars(&vars, format);
	va_start(vars.ap, format);
	handle_str_with_conversions(&vars);
	va_end(vars.ap);
	if (!vars.is_error)
		print_list(vars.list);
	clear_list(&vars.list);
	if (vars.word_count > INT_MAX)
		return (ERROR);
	return (vars.word_count);
}
