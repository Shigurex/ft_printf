/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:04:11 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/24 18:28:41 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static ssize_t	count_digit(int n)
{
	ssize_t	count;

	count = 1;
	while (n <= -10 || 10 <= n)
	{
		if (n > 0)
			n /= 10;
		else
			n /= -10;
		count++;
	}
	return (count);
}

char	*itoa_without_sign(t_vars *vars, int n)
{
	ssize_t	i;
	ssize_t	digit;
	char	*str;

	digit = count_digit(n);
	str = malloc(sizeof(char) * (digit + 1));
	if (!str)
	{
		vars->is_error = true;
		return (NULL);
	}
	i = digit - 1;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		if (n < 0)
			n /= -10;
		else
			n /= 10;
		i--;
	}
	str[digit] = '\0';
	return (str);
}

static size_t	count_digit_base(unsigned int n, size_t base_len)
{
	size_t	digit;

	digit = 1;
	while (n >= base_len)
	{
		n /= base_len;
		digit++;
	}
	return (digit);
}

char	*uitoa_base(unsigned int n, char *base)
{
	size_t	base_len;
	size_t	digits;
	size_t	i;
	char	*str;

	if (!base)
		return (NULL);
	base_len = ft_strlen(base);
	digits = count_digit_base(n, base_len);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	i = digits;
	str[i] = '\0';
	while (i > 0)
	{
		i--;
		str[i] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
