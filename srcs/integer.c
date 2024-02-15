/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:22:37 by yahokari          #+#    #+#             */
/*   Updated: 2024/02/16 02:32:16 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// TODO: flagsを用いた形式への対応
void	print_int(t_vars *vars, t_flags *flags, int n)
{
	(void)vars;
	(void)flags;
	ft_putnbr_fd(n, STDOUT_FILENO);
}
