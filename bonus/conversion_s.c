/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:25:18 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/06 15:25:33 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	handle_s(t_vars *vars, t_flags *flags, char *str)
{
	char	*tmp;

	(void)flags;
	tmp = ft_strdup(str);
	if (!tmp)
		return ;
	vars->word_count += ft_strlen(tmp);
	insert_list(&vars->list, tmp, CONVERSION);
}
