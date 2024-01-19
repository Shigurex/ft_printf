/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:54:40 by yahokari          #+#    #+#             */
/*   Updated: 2023/11/10 17:02:08 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnstr_fd(char *s, size_t n, int fd)
{
	size_t	len;
	size_t	tmp;
	size_t	i;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	i = 0;
	while (i < len)
	{
		if (len >= INT_MAX)
			tmp = INT_MAX;
		else
			tmp = len;
		write(fd, &s[i], tmp);
		i += tmp;
	}
}
