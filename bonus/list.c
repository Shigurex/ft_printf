/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:36:17 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/06 14:07:52 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static t_circ_list	*make_new_list(char *str)
{
	t_circ_list	*new_list;

	new_list = malloc(sizeof(t_circ_list));
	if (!new_list)
		return (NULL);
	new_list->str = str;
	new_list->next = new_list;
	new_list->prev = new_list;
	return (new_list);
}

static void	add_list_prev(t_circ_list **list, t_circ_list *new_list)
{
	t_circ_list	*current_list;
	t_circ_list	*prev_list;

	if (!list || !new_list)
		return ;
	if (!*list)
		*list = new_list;
	else
	{
		current_list = *list;
		prev_list = (*list)->prev;
		new_list->prev = prev_list;
		new_list->next = current_list;
		current_list->prev = new_list;
		prev_list->next = new_list;
	}
}

static void	add_list_next(t_circ_list **list, t_circ_list *new_list)
{
	t_circ_list	*current_list;
	t_circ_list	*next_list;

	if (!list || !new_list)
		return ;
	if (!*list)
		*list = new_list;
	else
	{
		current_list = *list;
		next_list = (*list)->next;
		new_list->prev = current_list;
		new_list->next = next_list;
		current_list->next = new_list;
		next_list->prev = new_list;
	}
}

void	insert_list(t_circ_list **list, char *str)
{
	if (!list)
		return ;
	if (!*list)
		add_list_prev(list, make_new_list(NULL));
	add_list_prev(list, make_new_list(str));
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


