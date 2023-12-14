/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:08:34 by yahokari          #+#    #+#             */
/*   Updated: 2023/12/12 16:22:38 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	print_conversion_p(t_vars *vars, t_flags *flags, void *p)
{
	ft_putstr_fd(ALT_HEX, STDOUT_FILENO);
	vars->word_count += ft_strlen(ALT_HEX);
	print_conversion_x(vars, flags, (uintptr_t)p);
}
