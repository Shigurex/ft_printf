/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:44:59 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/01 19:55:29 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdio.h>

#define GREEN "\e[32m"
#define RED "\e[31m"
#define DEFAULT "\e[39m"

#define F(format, ...) { \
	int	expected = printf(format, __VA_ARGS__); \
	fflush(stdout); \
	int	actual = ft_printf(format, __VA_ARGS__); \
	fflush(stdout); \
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
	printf("\n<---------- [conversion %c] ---------->\n", 'c');
	F("%10c\n", 'a');
	F("%-10c\n", 'a');
	F("%-0c\n", 'a');
	F("%0c\n", 'a');

	printf("\n<---------- [conversion %c] ---------->\n", 's');
	F("%-10.3sa\n", "hello");
	F("%-10.3sa\n", NULL);
	F("%10.3sa\n", "ewr");
	F("%5.3sa\n", "ewrerew");
	F("%5.0sa\n", "ewrerew");
	F("%0.1sa\n", "ewrerew");
	F("%0.0sa\n", "ewrerew");
	F("%4sa\n", "ewrerew");
	F("%-sa\n", "ewrerew");
	//F("%10.4sa\n", NULL);

	printf("\n<---------- [conversion %c] ---------->\n", 'd');
	F("%010.6da\n", 324);
	F("%010.6da\n", -324);
	F("%+10.1da\n", 324);
	F("%+10.1da\n", -324);
	F("%6.6da\n", 324);
	F("%6.6da\n", -324);
	
	// F("aa%s%-10caa\n", "hello", 'f');
	// F("aa%s%100caa\n", "hello", 'f');
	// F("aa%s%caa\nd", "hello", 'f');
	// F("aa%10.4s%caa\n", "hello", 'f');
	// F("%c", '\n');

	printf("\n<---------- [conversion %c] ---------->\n", '%');
	F("%4sa%10%\n", "Hello");
	F("%4sa%-10%\n", "Hello");
	F("%4sa%-010%\n", "Hello");
	F("%4sa%05%\n", "Hello");
	system("leaks -q a.out");
	return (0);
}
