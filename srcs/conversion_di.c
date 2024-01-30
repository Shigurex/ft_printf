/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:22:37 by yahokari          #+#    #+#             */
/*   Updated: 2024/01/31 01:57:48 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	print_conversion_di(t_vars *vars, t_flags *flags, int n)
{
	(void)vars;
	(void)flags;
	ft_putnbr_fd(n, STDOUT_FILENO);
}
