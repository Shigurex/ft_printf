/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 00:34:56 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/23 15:37:45 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<string.h>
# include	<limits.h>
# include	<stdbool.h>
# include	"libft/libft.h"

# define ERROR -1

typedef enum e_type
{
	SENTINEL,
	CONVERSION,
	SPECIFICATION,
	NORMAL_STRING
}	t_type;

typedef struct s_flags
{
	bool	minus;
	bool	zero;
	bool	sharp;
	bool	space;
	bool	plus;
	bool	dot;
	int		width;
	int		precision;
}	t_flags;

typedef struct s_circ_list
{
	char				*str;
	t_type				type;
	struct s_circ_list	*next;
	struct s_circ_list	*prev;
}	t_circ_list;

typedef struct s_vars
{
	va_list		ap;
	int			word_count;
	const char	*str;
	t_circ_list	*list;
	bool		is_error;
}	t_vars;

/* ft_printf.c */
int			ft_printf(const char *format, ...);

/* list.c */
void		insert_list(t_circ_list **list, char *str, t_type type);
void		print_list(t_circ_list *list);
void		clear_list(t_circ_list **list);
void		insert_list_after_last_type(t_circ_list **list, char *str, \
		t_type type, t_type last_type);
void		insert_list_before_last_type(t_circ_list **list, char *str, \
		t_type type, t_type last_type);

/* list_utils.c */
t_circ_list	*make_new_list(char *str, t_type type);
void		add_list_prev(t_circ_list **list, t_circ_list *new_list);
void		add_list_next(t_circ_list **list, t_circ_list *new_list);
t_circ_list	*find_last_type(t_circ_list *list, t_type type);

/* ft_substr_size_t.c */
char		*substr_size_t(char const *s, size_t start, size_t len);

/* conversions.c */
void		handle_conversions(t_vars *vars);

/* conversion_c.c */
void		handle_c_char(t_vars *vars, char c);
void		handle_c(t_vars *vars, t_flags *flags, char c);

/* conversion_s.c */
void		handle_s(t_vars *vars, t_flags *flags, char *str);

/* conversion_percent.c */
void		handle_percent(t_vars *vars, t_flags *flags);

/* string.c */
char		*make_char_reps_string(size_t size, char c);

/* flags.c */
void		init_flags(t_flags *flags);
void		check_flags(t_vars *vars, t_flags *flags);

#endif