/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:08:34 by yahokari          #+#    #+#             */
/*   Updated: 2024/02/24 14:55:38 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	print_address(t_vars *vars, t_flags *flags, uintptr_t p)
{
	size_t	len_hex_lower;

	ft_putstr_fd(ALT_HEX_LOWER, STDOUT_FILENO);
	len_hex_lower = ft_strlen(ALT_HEX_LOWER);
	vars->word_count += len_hex_lower;
	if (flags->width >= (int)len_hex_lower)
		flags->width -= len_hex_lower;
	print_unsigned(vars, flags, p, HEX_LOWER);
}
