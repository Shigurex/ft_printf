/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:43:25 by yahokari          #+#    #+#             */
/*   Updated: 2024/02/14 22:23:37 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uint_hex_lower(t_vars *vars, t_flags *flags, unsigned int n)
{
	if (n == 0 && flags->alt_form)
		flags->alt_form = false;
	print_unsigned(vars, flags, n, HEX_LOWER);
}
