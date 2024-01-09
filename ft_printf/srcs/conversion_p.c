/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:08:34 by yahokari          #+#    #+#             */
/*   Updated: 2024/01/09 17:28:19 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	print_conversion_p(t_vars *vars, t_flags *flags, uintptr_t p)
{
	ft_putstr_fd(ALT_HEX, STDOUT_FILENO);
	vars->word_count += ft_strlen(ALT_HEX);
	// need modified
	print_conversion_x(vars, flags, (uintptr_t)p);
}
