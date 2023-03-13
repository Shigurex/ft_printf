/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:44:59 by yahokari          #+#    #+#             */
/*   Updated: 2023/03/14 00:59:55 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"tester.h"

//# include	"../ft_printf.h"
//# include	<stdio.h>
//# include	<fcntl.h>

//# define BLACK "\e[30m"
//# define RED "\e[31m"
//# define GREEN "\e[32m"
//# define YELLOW "\e[33m"
//# define BLUE "\e[34m"
//# define DEFAULT "\e[39m"

//# define PRINTF_OUT "printf.txt"
//# define FT_PRINTF_OUT "ft_printf.txt"

//#define CHECK(expression) ((expression)? GREEN"OK"DEFAULT : RED"NG"DEFAULT)

//#define MESSAGE(message) (YELLOW message DEFAULT)

//#define F(...) { \
//	int	stdout_fd; \
//	stdout_fd = set_file(PRINTF_OUT); \
//	int	expected = printf(__VA_ARGS__); \
//	fflush(stdout); \
//	unset_file(stdout_fd); \
//	stdout_fd = set_file(FT_PRINTF_OUT); \
//	int	actual = ft_printf(__VA_ARGS__); \
//	fflush(stdout); \
//	unset_file(stdout_fd); \
//	printf("%sCase: (%s)%s\n", BLUE, #__VA_ARGS__, DEFAULT); \
//	printf("%s %s	%s %s\n", MESSAGE("Output:"), CHECK(!system("diff printf.txt ft_printf.txt")), MESSAGE("Return:"), CHECK(expected == actual)); \
//	fflush(stdout); \
//	unlink(PRINTF_OUT); \
//	unlink(FT_PRINTF_OUT); \
//}

int	main(void)
{
	setvbuf(stdout, (char *)NULL, _IONBF, 0);

	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 'c');
	F("%10c\n", 'a');
	F("%-10c\n", 'a');
	F("%-0c\n", 'a');
	F("%0c\n", 'a');

	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 's');
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

	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 'u');
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

	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", '%');
	F("%4sa%10%\n", "Hello");
	F("%4sa%-10%\n", "Hello");
	F("%4sa%-010%\n", "Hello");
	F("%4sa%05%\n", "Hello");

	printf("\n<-------------------------------------------------- [conversion %c] -------------------------------------------------->\n", 'd');
	F("%10d", 1000);
	F("%10.5d", 1000);

	//system("leaks -q a.out");
	return (0);
}
