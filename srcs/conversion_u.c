/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:49:19 by yahokari          #+#    #+#             */
/*   Updated: 2024/01/19 09:57:25 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conversion_u(t_vars *vars, t_flags *flags, unsigned int n)
{
	if (n == 0 && flags->alt_form)
		flags->alt_form = false;
	print_unsigned(vars, flags, n, DECIMAL);
}