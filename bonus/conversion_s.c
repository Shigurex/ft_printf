/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:25:18 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/07 18:15:01 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	handle_s(t_vars *vars, t_flags *flags, char *str)
{
	char	*tmp;
	char	*spaces;
	size_t	tmp_len;

	// if (!str) //need modified
	// {
	// 	str = ft_strdup("(null)");
	// 	if (!str)
	// 		return ;
	// }
	if (flags->dot)
		tmp = substr_size_t(str, 0, flags->precision);
	else
		tmp = ft_strdup(str);
	if (!tmp)
		return ;
	tmp_len = ft_strlen(tmp);
	vars->word_count += tmp_len;
	insert_list(&vars->list, tmp, CONVERSION);
	if (flags->width > 0 && (size_t)flags->width > tmp_len)
	{
		spaces = make_char_reps_string(flags->width - tmp_len, ' ');
		if (!spaces)
			return ;
		if (!flags->minus)
			insert_list_before_last_type(&vars->list, spaces, \
				SPECIFICATION, CONVERSION);
		else
			insert_list_after_last_type(&vars->list, spaces, \
				SPECIFICATION, CONVERSION);
		vars->word_count += ft_strlen(spaces);
	}
}
