/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:44:59 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/06 12:00:33 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdio.h>

#define GREEN "\e[32m"
#define RED "\e[31m"
#define DEFAULT "\e[39m"

#define F(format, ...) { \
	int	expected = printf(format, __VA_ARGS__); \
	int	actual = ft_printf(format, __VA_ARGS__); \
	check_diff(expected, actual); \
}

void	check_diff(int expected, int actual)
{
	if (expected == actual)
		printf("Return value: %sOK%s [printf: %d, ft_printf: %d]\n", GREEN, DEFAULT, expected, actual);
	else
		printf("Return value: %sNG%s [printf: %d, ft_printf: %d]\n", RED, DEFAULT, expected, actual);
}

int	main(void)
{
	F("aa%s%22121324324321caa\n", "hello", 'f');
	F("aa%s%caa\n", "hello", 'f');
	F("aa%s%caa\n", "hello", 'f');
	return (0);
}
