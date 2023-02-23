/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:25:18 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/23 12:17:17 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

//static char	*itoa_with_flags(t_vars *vars, int n, t_flags *flags, int index)
//{
//	char	*str;

//	if (n == 0)
//	{
//		str = malloc(sizeof(char) * (index + 1));
//		if (!str)
//			return (NULL);
//	}
//	else
//		str = itoa_with_flags(vars, n / 10, flags, index + 1);
//	if (!str)
//		return (NULL);
//}

void	handle_d(t_vars *vars, t_flags *flags, char c)
{
	char	*tmp;
	char	*spaces;

	vars->word_count += 1;
	tmp = substr_size_t(&c, 0, 1);
	if (!tmp)
		return ;
	insert_list(&vars->list, tmp, CONVERSION);
	if (flags->width > 1)
	{
		spaces = make_char_reps_string(flags->width - 1, ' ');
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
