/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:44:59 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/13 21:39:26 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	<stdio.h>
#include	<fcntl.h>

#define GREEN "\e[32m"
#define RED "\e[31m"
#define DEFAULT "\e[39m"

#define F(format, ...) { \
	int	stdout_fd; \
	stdout_fd = set_file("printf.txt"); \
	int	expected = printf(format, __VA_ARGS__); \
	fflush(stdout); \
	unset_file(stdout_fd); \
	stdout_fd = set_file("ft_printf.txt"); \
	int	actual = ft_printf(format, __VA_ARGS__); \
	fflush(stdout); \
	unset_file(stdout_fd); \
	check_diff(expected, actual); \
	fflush(stdout); \
	unlink("printf.txt"); \
	unlink("ft_printf.txt"); \
}

int	set_file(char *file)
{
	int	file_fd;
	int	stdout_fd;

	file_fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file_fd < 0)
		return (file_fd);
	stdout_fd = dup(STDOUT_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
	return (stdout_fd);
}

void	unset_file(int stdout_fd)
{
	dup2(stdout_fd, STDOUT_FILENO);
	close(stdout_fd);
}

void	check_diff(int expected, int actual)
{
	if (!system("diff printf.txt ft_printf.txt"))
		printf("Value: %sOK%s\n", GREEN, DEFAULT);
	else
		printf("Value: %sNG%s\n", RED, DEFAULT);
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

	printf("\n<---------- [conversion %c] ---------->\n", 'u');
	F("%010.6ua\n", 324);
	F("%08.6ua\n", 324);
	F("%8.6ua\n", 324);
	F("%04.6ua\n", 324);
	F("%06.4ua\n", 324);
	F("%0.4ua\n", 324);
	F("%06.2ua\n", 324);
	F("%02.6ua\n", 324);
	F("%0.6ua\n", 324);
	F("%+10.1ua\n", 324);
	F("%+10.1ua\n", 324);
	F("%6.2ua\n", 324);
	F("%6.6ua\n", 324);
	F("%0u\n", 0);
	F("%5u\n", 0);
	F("%.0u\n", 0);
	F("%.0u\n", 1);
	F("%-010.6ua\n", 324);
	F("%-08.6ua\n", 324);
	F("%-8.6ua\n", 324);
	F("%-04.6ua\n", 324);
	F("%-06.4ua\n", 324);
	F("%-0.4ua\n", 324);
	F("%010u\n", 1000);
	F("%010.1u\n", 1000);
	F("%010.0u\n", 1000);
	F("%10u\n", 1000);
	F("%010u\n", 1000);
	F("%10.0u\n", 1000);
	//F("%010.-1u\n", 1000);
	
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

	//system("leaks -q a.out");
	return (0);
}
