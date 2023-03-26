#ifndef DEFINE_H
# define DEFINE_H

# include	"../ft_printf.h"
# include	<stdio.h>
# include	<fcntl.h>

# define BLACK "\e[30m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define DEFAULT "\e[39m"

# define PRINTF_OUT "printf.txt"
# define FT_PRINTF_OUT "ft_printf.txt"
# define DIFF_OUT "diff.txt"

# define CHECK(expression) ((expression)? GREEN"OK"DEFAULT : RED"NG"DEFAULT)

# define MESSAGE(message) (YELLOW message DEFAULT)

//# define F(...) { \
//	int	stdout_fd; \
//	stdout_fd = set_file(PRINTF_OUT); \
//	int	expected = printf(__VA_ARGS__); \
//	fflush(stdout); \
//	unset_file(stdout_fd); \
//	stdout_fd = set_file(FT_PRINTF_OUT); \
//	int	actual = ft_printf(__VA_ARGS__); \
//	fflush(stdout); \
//	unset_file(stdout_fd); \
//	printf("%sCase: %-30s%s	", BLUE, "("#__VA_ARGS__")", DEFAULT); \
//	printf("%s %s	%s %s	", MESSAGE("Output:"), CHECK(system("diff "PRINTF_OUT" "FT_PRINTF_OUT" > "DIFF_OUT) == 0), MESSAGE("Return:"), CHECK(expected == actual)); \
//	printf("%s[printf: %s%d%s, ft_printf: %s%d%s]%s\n", YELLOW, (expected == actual)? GREEN : RED, expected, YELLOW, (expected == actual)? GREEN : RED, actual, YELLOW, DEFAULT); \
//	fflush(stdout); \
//	printf("%s", RED); \
//	system("cat "DIFF_OUT); \
//	printf("%s", DEFAULT); \
//	unlink(PRINTF_OUT); \
//	unlink(FT_PRINTF_OUT); \
//	unlink(DIFF_OUT); \
//}

# define F(...) { \
	int	stdout_fd; \
	stdout_fd = set_file(PRINTF_OUT); \
	int	expected = printf(__VA_ARGS__); \
	fflush(stdout); \
	unset_file(stdout_fd); \
	stdout_fd = set_file(FT_PRINTF_OUT); \
	int	actual = ft_printf(__VA_ARGS__); \
	fflush(stdout); \
	unset_file(stdout_fd); \
	printf("%sCase: %-30s%s	", BLUE, "("#__VA_ARGS__")", DEFAULT); \
	printf("%s %s	%s %s	", MESSAGE("Output:"), CHECK(system("diff "PRINTF_OUT" "FT_PRINTF_OUT" > "DIFF_OUT) == 0), MESSAGE("Return:"), CHECK(expected == actual)); \
	printf("%s[printf: %s%d%s, ft_printf: %s%d%s]%s\n", YELLOW, (expected == actual)? GREEN : RED, expected, YELLOW, (expected == actual)? GREEN : RED, actual, YELLOW, DEFAULT); \
	fflush(stdout); \
	printf("printf\t\t: "); \
	system("cat "PRINTF_OUT); \
	printf("ft_printf\t: "); \
	system("cat "FT_PRINTF_OUT); \
	printf("%s", RED); \
	system("cat "DIFF_OUT); \
	printf("%s", DEFAULT); \
	unlink(PRINTF_OUT); \
	unlink(FT_PRINTF_OUT); \
	unlink(DIFF_OUT); \
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

#endif
