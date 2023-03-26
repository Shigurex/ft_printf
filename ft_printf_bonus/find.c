/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:07:45 by yahokari          #+#    #+#             */
/*   Updated: 2023/02/03 13:21:25 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

t_circ_list	*find_last_type(t_circ_list *list, t_type type)
{
	t_circ_list	*first_list;

	if (!list)
		return (NULL);
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
