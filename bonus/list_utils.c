/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:46:05 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/06 15:46:47 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

t_circ_list	*make_new_list(char *str, t_type type)
{
	t_circ_list	*new_list;

	new_list = malloc(sizeof(t_circ_list));
	if (!new_list)
		return (NULL);
	new_list->str = str;
	new_list->type = type;
	new_list->next = new_list;
	new_list->prev = new_list;
	return (new_list);
}

void	add_list_prev(t_circ_list **list, t_circ_list *new_list)
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

void	add_list_next(t_circ_list **list, t_circ_list *new_list)
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

t_circ_list	*find_last_type(t_circ_list *list, t_type type)
{
	t_circ_list	*first_list;

	first_list = list;
	list = list->prev;
	while (list != first_list)
	{
		if (list->type == type)
			return (list);
		list = list->prev;
	}
	return (NULL);
}
