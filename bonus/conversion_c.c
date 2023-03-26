/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:25:18 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/24 18:48:59 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	handle_c_char(t_vars *vars, char c)
{
	char	*tmp;

	vars->word_count += 1;
	tmp = substr_size_t(&c, 0, 1);
	if (!tmp)
	{
		vars->is_error = true;
		return ;
	}
	insert_list(&vars->list, tmp, CONVERSION);
}

void	handle_c_spaces(t_vars *vars, t_flags *flags)
{
	char	*spaces;

	if (flags->width > 1)
	{
		spaces = make_char_reps_string(flags->width - 1, ' ');
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

void	handle_c(t_vars *vars, t_flags *flags, char c)
{
	handle_c_char(vars, c);
	handle_c_spaces(vars, flags);
}
