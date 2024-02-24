/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:22:07 by yahokari          #+#    #+#             */
/*   Updated: 2024/02/14 22:22:18 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	print_char(t_vars *vars, t_flags *flags, unsigned char c)
{
	if (flags->width <= 1)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		++vars->word_count;
	}
	else if (flags->left_justify)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		ft_putnchar_fd(flags->pad_char, flags->width - 1, STDOUT_FILENO);
		vars->word_count += flags->width;
	}
	else
	{
		ft_putnchar_fd(flags->pad_char, flags->width - 1, STDOUT_FILENO);
		ft_putchar_fd(c, STDOUT_FILENO);
		vars->word_count += flags->width;
	}
}
