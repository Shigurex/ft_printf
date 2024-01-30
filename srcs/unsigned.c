/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:28:29 by yahokari          #+#    #+#             */
/*   Updated: 2024/01/31 01:50:49 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len_in_str(size_t n, char *base)
{
	int		len;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = 1;
	while (n >= base_len)
	{
		n /= base_len;
		++len;
	}
	return (len);
}

void	print_unsigned(t_vars *vars, t_flags *flags, size_t n, char *base)
{
	int		str_len;

	str_len = (flags->alt_form ? 2 : 0) + \
		(num_len_in_str(n, base) < flags->precision ? flags->precision : num_len_in_str(n, base));
	if (flags->width <= str_len)
	{
		if (flags->alt_form)
			ft_putstr_fd((ft_strcmp(HEX_LOWER, base) == 0) ? ALT_HEX_LOWER : ALT_HEX_UPPER, STDOUT_FILENO);
		if (num_len_in_str(n, base) < flags->precision)
			ft_putnchar_fd('0', flags->precision - num_len_in_str(n, base), STDOUT_FILENO);
		ft_putnbr_base_fd(n, base, STDOUT_FILENO);
		vars->word_count += str_len;
	}
	else if (flags->left_justify)
	{
		if (flags->alt_form)
			ft_putstr_fd((ft_strcmp(HEX_LOWER, base) == 0) ? ALT_HEX_LOWER : ALT_HEX_UPPER, STDOUT_FILENO);
		if (num_len_in_str(n, base) < flags->precision)
			ft_putnchar_fd('0', flags->precision - num_len_in_str(n, base), STDOUT_FILENO);
		else if (flags->pad_char == '0' && num_len_in_str(n, base) + (flags->alt_form ? 2 : 0) < flags->width)
			ft_putnchar_fd(flags->pad_char, flags->width - (flags->alt_form ? 2 : 0) - num_len_in_str(n, base), STDOUT_FILENO);
		ft_putnbr_base_fd(n, base, STDOUT_FILENO);
		if (flags->pad_char == ' ')
			ft_putnchar_fd(flags->pad_char, flags->width - str_len, STDOUT_FILENO);
		vars->word_count += flags->width;
	}
	else
	{
		if (flags->pad_char == ' ')
			ft_putnchar_fd(flags->pad_char, flags->width - str_len, STDOUT_FILENO);
		if (flags->alt_form)
			ft_putstr_fd((ft_strcmp(HEX_LOWER, base) == 0) ? ALT_HEX_LOWER : ALT_HEX_UPPER, STDOUT_FILENO);
		if (num_len_in_str(n, base) < flags->precision)
			ft_putnchar_fd('0', flags->precision - num_len_in_str(n, base), STDOUT_FILENO);
		else if (flags->pad_char == '0' && num_len_in_str(n, base) + (flags->alt_form ? 2 : 0) < flags->width)
			ft_putnchar_fd(flags->pad_char, flags->width - (flags->alt_form ? 2 : 0) - num_len_in_str(n, base), STDOUT_FILENO);
		ft_putnbr_base_fd(n, base, STDOUT_FILENO);
		vars->word_count += flags->width;
	}
}
