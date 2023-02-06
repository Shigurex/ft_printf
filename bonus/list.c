/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:36:17 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/06 15:46:32 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	insert_list(t_circ_list **list, char *str, t_type type)
{
	if (!list)
		return ;
	if (!*list)
		add_list_prev(list, make_new_list(NULL, SENTINEL));
	add_list_prev(list, make_new_list(str, type));
}

void	print_list(t_circ_list *list)
{
	t_circ_list	*first_list;

	if (!list)
		return ;
	first_list = list;
	list = list->next;
	while (list != first_list)
	{
		if (list->str)
			ft_putstr_fd(list->str, STDOUT_FILENO);
		list = list->next;
	}
}

void	clear_list(t_circ_list **list)
{
	t_circ_list	*first_list;
	t_circ_list	*buf_list;
	t_circ_list	*tmp_list;

	if (!list)
		return ;
	first_list = (*list);
	buf_list = (*list)->next;
	while (buf_list != first_list)
	{
		tmp_list = buf_list->next;
		if (buf_list->str)
			free(buf_list->str);
		free(buf_list);
		buf_list = tmp_list;
	}
	free(buf_list);
	*list = NULL;
}

void	insert_list_after_last_type(t_circ_list **list, char *str, \
	t_type type, t_type last_type)
{
	t_circ_list	*last_type_list;

	last_type_list = find_last_type(*list, last_type);
	if (!last_type_list)
		insert_list(list, str, type);
	else
		add_list_next(&last_type_list, make_new_list(str, type));
}

void	insert_list_before_last_type(t_circ_list **list, char *str, \
	t_type type, t_type last_type)
{
	t_circ_list	*last_type_list;

	last_type_list = find_last_type(*list, last_type);
	if (!last_type_list)
		insert_list(list, str, type);
	else
		add_list_prev(&last_type_list, make_new_list(str, type));
}
