/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:04:11 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/01 21:36:44 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

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
