/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:25:18 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/01 20:25:22 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static char	*handle_s_str(t_vars *vars, t_flags *flags, char *str)
{
	char	*tmp;
	size_t	tmp_len;
	bool	is_str_null;

	is_str_null = false;
	if (!str)
	{
		is_str_null = true;
		str = ft_strdup("(null)");
		if (!str)
			return (NULL);
	}
	if (flags->dot)
		tmp = substr_size_t(str, 0, flags->precision);
	else
		tmp = ft_strdup(str);
	if (is_str_null)
		free(str);
	if (!tmp)
		return (NULL);
	tmp_len = ft_strlen(tmp);
	vars->word_count += tmp_len;
	insert_list(&vars->list, tmp, CONVERSION);
	return (tmp);
}

static void	handle_s_spaces(t_vars *vars, t_flags *flags, size_t len)
{
	char	*spaces;

	if (flags->width > 0 && (size_t)flags->width > len)
	{
		spaces = make_char_reps_string(flags->width - len, ' ');
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

void	handle_s(t_vars *vars, t_flags *flags, char *str)
{
	char	*tmp;
	size_t	tmp_len;

	tmp = handle_s_str(vars, flags, str);
	if (!tmp)
	{
		vars->is_error = true;
		return ;
	}
	tmp_len = ft_strlen(tmp);
	handle_s_spaces(vars, flags, tmp_len);
}
