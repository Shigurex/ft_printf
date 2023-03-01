/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:30:41 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/23 15:37:21 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	handle_percent_zeros_and_spaces(t_vars *vars, t_flags *flags)
{
	char	*zeros_or_spaces;

	if (flags->width > 1)
	{
		if (flags->zero && !flags->minus)
			zeros_or_spaces = make_char_reps_string(flags->width - 1, '0');
		else
			zeros_or_spaces = make_char_reps_string(flags->width - 1, ' ');
		if (!zeros_or_spaces)
		{
			vars->is_error = true;
			return ;
		}
		if (!flags->minus)
			insert_list_before_last_type(&vars->list, zeros_or_spaces, \
				SPECIFICATION, CONVERSION);
		else
			insert_list_after_last_type(&vars->list, zeros_or_spaces, \
				SPECIFICATION, CONVERSION);
		vars->word_count += ft_strlen(zeros_or_spaces);
	}
}

void	handle_percent(t_vars *vars, t_flags *flags)
{
	handle_c_char(vars, '%');
	handle_percent_zeros_and_spaces(vars, flags);
}
