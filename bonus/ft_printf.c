/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:34:53 by yahokari          #+#    #+#             */
/*   Updated: 2023/01/31 21:02:00 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	handle_normal_str(t_vars *vars, char *str, size_t start, size_t len)
{
	char	*tmp;

	tmp = substr_size_t(str, start, len);
	if (!tmp)
		return ;
	vars->word_count += ft_strlen(tmp);
	insert_list(&vars->list, tmp);
}

void	handle_str_with_conversions(t_vars *vars)
{
	const char	*tmp;
	size_t		len;

	len = 0;
	tmp = vars->str;
	while (!vars->is_error)
	{
		if (!*vars->str || *vars->str == '%')
		{
			handle_normal_str(vars, (char *)tmp, 0, len);
			len = 0;
		}
		if (!*vars->str)
			break ;
		if (*vars->str == '%')
		{
			handle_conversions(vars);
			tmp = vars->str;
			continue ;
		}
		else
			len++;
		vars->str++;
	}
}

void	init_vars(t_vars *vars, const char *format)
{
	vars->str = format;
	vars->word_count = 0;
	vars->list = NULL;
	vars->is_error = false;
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
		return (-1);
	return (vars.word_count);
}
