/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:39:26 by yahokari          #+#    #+#             */
/*   Updated: 2023/12/05 23:44:37 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnbr_base_fd(unsigned int n, char *base, int fd)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_putnbr_base_fd(n / base_len, base, fd);
	ft_putchar_fd(base[n % base_len], fd);
}
