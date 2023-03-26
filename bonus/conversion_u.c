/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:59:55 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/24 18:23:17 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	handle_u_spaces(t_vars *vars, t_flags *flags)
{
	char	*spaces;

	if (flags->width > 0 && flags->width > flags->precision)
	{
		spaces = make_char_reps_string(flags->width - flags->precision, ' ');
		if (!spaces)
		{
			vars->is_error = true;
			return ;
		}
		if (!flags->minus)
			insert_list_before_last_type(&vars->list, spaces, \
				SPECIFICATION, CONVERSION);
		else
			insert_list_after_last_type(&vars->list, spaces, \
				SPECIFICATION, CONVERSION);
		vars->word_count += ft_strlen(spaces);
	}
}

static void	handle_u_zeros_and_spaces(t_vars *vars, t_flags *flags, size_t len)
{
	char	*zeros_or_spaces;

	if ((size_t)flags->precision > len)
	{
		if (flags->zero)
			zeros_or_spaces = make_char_reps_string(flags->precision - len, '0');
		else
			zeros_or_spaces = make_char_reps_string(flags->precision - len, ' ');
		if (!zeros_or_spaces)
		{
			vars->is_error = true;
			return ;
		}
		insert_list_before_last_type(&vars->list, zeros_or_spaces, \
			SPECIFICATION, CONVERSION);
		vars->word_count += ft_strlen(zeros_or_spaces);
	}
}

void	handle_u(t_vars *vars, t_flags *flags, unsigned int n)
{
	char	*str;
	size_t	str_len;

	if (n == 0 && flags->width == 0 && flags->dot)
		return ;
	str = uitoa_base(n, "0123456789");
	if (!str)
	{
		vars->is_error = true;
		return ;
	}
	str_len = ft_strlen(str);
	if (flags->precision > 0)
		flags->zero = true;
	if ((size_t)flags->precision < str_len)
		flags->precision = str_len;
	if (flags->width > 0 && !flags->dot && !flags->minus)
		flags->precision = flags->width;
	if (flags->precision > flags->width)
		flags->width = flags->precision;
	insert_list(&vars->list, str, CONVERSION);
	vars->word_count += str_len;
	handle_u_spaces(vars, flags);
	handle_u_zeros_and_spaces(vars, flags, str_len);
}
