/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:17:22 by yahokari          #+#    #+#             */
/*   Updated: 2023/01/21 16:31:53 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	tmp;

	len = ft_strlen(s);
	while (*s)
	{
		if (len >= INT_MAX)
			tmp = INT_MAX;
		else
			tmp = len;
		write(fd, s, tmp);
		s += tmp;
	}
}