/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:41:03 by yahokari          #+#    #+#             */
/*   Updated: 2023/11/10 16:15:07 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnchar_fd(char c, size_t n, int fd)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
}
