/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:25:18 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/06 11:27:53 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	handle_c(t_vars *vars, t_flags *flags, char c)
{
	char	*tmp;
	char	*spaces;

	vars->word_count += 1;
	tmp = substr_size_t(&c, 0, 1);
	if (!tmp)
		return ;
	if (flags->width > 1)
	{
		spaces = make_char_reps_string(flags->width - 1, ' ');
		if (!spaces)
		{
			free(tmp);
			return ;
		}
	}
	if (flags->width > 1 && !flags->minus)
		insert_list(&vars->list, spaces);
	insert_list(&vars->list, tmp);
	if (flags->width > 1 && flags->minus)
	{
		insert_list(&vars->list, spaces);
		vars->word_count += ft_strlen(spaces);
	}
}
