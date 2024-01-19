/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:08:34 by yahokari          #+#    #+#             */
/*   Updated: 2024/01/19 09:44:22 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	print_conversion_p(t_vars *vars, t_flags *flags, uintptr_t p)
{
	ft_putstr_fd(ALT_HEX_LOWER, STDOUT_FILENO);
	vars->word_count += ft_strlen(ALT_HEX_LOWER);
	if (flags->width >= num_len_in_str(p, HEX_LOWER))
		flags->width -= num_len_in_str(p, HEX_LOWER);
	print_unsigned(vars, flags, p, HEX_LOWER);
}
