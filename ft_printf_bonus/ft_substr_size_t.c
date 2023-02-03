/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_size_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:35:50 by yahokari          #+#    #+#             */
/*   Updated: 2023/01/20 21:35:51 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static size_t	malloc_size(char const *s, size_t start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len <= start)
		return (1);
	else if (s_len + 1 < start + len)
		return (s_len - start + 1);
	else
		return (len + 1);
}

char	*substr_size_t(char const *s, size_t start, size_t len)
{
	size_t	i;
	char	*substring;

	if (s == NULL)
		return (NULL);
	substring = malloc(sizeof(char) * malloc_size(s, start, len));
	if (substring == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		substring[0] = '\0';
		return (substring);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}