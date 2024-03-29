/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:42:10 by yahokari          #+#    #+#             */
/*   Updated: 2024/02/14 22:44:10 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	print_str(t_vars *vars, t_flags *flags, char *str)
{
	int	str_len;

	if (!str)
		return (print_str(vars, flags, "(null)"));
	str_len = ft_strlen(str);
	if (flags->precision != UNSET && flags->precision < str_len)
		str_len = flags->precision;
	if (flags->width <= str_len)
	{
		ft_putnstr_fd(str, str_len, STDOUT_FILENO);
		vars->word_count += str_len;
	}
	else if (flags->left_justify)
	{
		ft_putnstr_fd(str, str_len, STDOUT_FILENO);
		ft_putnchar_fd(flags->pad_char, flags->width - str_len, STDOUT_FILENO);
		vars->word_count += flags->width;
	}
	else
	{
		ft_putnchar_fd(flags->pad_char, flags->width - str_len, STDOUT_FILENO);
		ft_putnstr_fd(str, str_len, STDOUT_FILENO);
		vars->word_count += flags->width;
	}
}
