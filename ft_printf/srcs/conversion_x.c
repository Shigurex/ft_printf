/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:43:25 by yahokari          #+#    #+#             */
/*   Updated: 2023/12/07 13:33:57 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n, unsigned int base)
{
	int	len;

	len = 1;
	while (n >= base)
	{
		n /= 16;
		++len;
	}
	return (len);
}

void	print_conversion_x(t_vars *vars, t_flags *flags, unsigned int n)
{
	bool	is_alt_form;
	int		str_len;

	if (n != 0 && flags->alt_form)
		is_alt_form = true;
	else
		is_alt_form = false;
	str_len = (is_alt_form ? 2 : 0) + \
		(ft_numlen(n, 16) < flags->precision ? flags->precision : ft_numlen(n, 16));
	if (flags->width <= str_len)
	{
		if (is_alt_form)
			ft_putstr_fd(ALT_HEX, STDOUT_FILENO);
		// print hex
		if (ft_numlen(n, 16) < flags->precision)
			ft_putnchar_fd('0', flags->precision - ft_numlen(n, 16), STDOUT_FILENO);
		ft_putnbr_base_fd(n, HEX_LOWER, STDOUT_FILENO);
		vars->word_count += str_len;
	}
	else if (flags->left_justify)
	{
		if (is_alt_form)
			ft_putstr_fd(ALT_HEX, STDOUT_FILENO);
		// print hex
		if (ft_numlen(n, 16) < flags->precision)
			ft_putnchar_fd('0', flags->precision - ft_numlen(n, 16), STDOUT_FILENO);
		else if (flags->pad_char == '0' && ft_numlen(n, 16) + (is_alt_form ? 2 : 0) < flags->width)
			ft_putnchar_fd(flags->pad_char, flags->width - (is_alt_form ? 2 : 0) - ft_numlen(n, 16), STDOUT_FILENO);
		ft_putnbr_base_fd(n, HEX_LOWER, STDOUT_FILENO);
		if (flags->pad_char == ' ')
			ft_putnchar_fd(flags->pad_char, flags->width - str_len, STDOUT_FILENO);
		vars->word_count += flags->width;
	}
	else
	{
		if (flags->pad_char == ' ')
			ft_putnchar_fd(flags->pad_char, flags->width - str_len, STDOUT_FILENO);
		if (is_alt_form)
			ft_putstr_fd(ALT_HEX, STDOUT_FILENO);
		// print hex
		if (ft_numlen(n, 16) < flags->precision)
			ft_putnchar_fd('0', flags->precision - ft_numlen(n, 16), STDOUT_FILENO);
		else if (flags->pad_char == '0' && ft_numlen(n, 16) + (is_alt_form ? 2 : 0) < flags->width)
			ft_putnchar_fd(flags->pad_char, flags->width - (is_alt_form ? 2 : 0) - ft_numlen(n, 16), STDOUT_FILENO);
		ft_putnbr_base_fd(n, HEX_LOWER, STDOUT_FILENO);
		vars->word_count += flags->width;
	}
}
