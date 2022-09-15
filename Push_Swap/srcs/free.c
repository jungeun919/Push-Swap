/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:54:12 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/14 07:56:26 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_list *list)
{
	t_node	*temp;

	while (list->top)
	{
		temp = list->top->next;
		free(list->top);
		list->top = NULL;
		list->top = temp;
	}
	free(list);
	list = NULL;
}

void	free_lists(t_lists *lists)
{
	free_list(lists->a);
	free_list(lists->b);
	free(lists);
	lists = NULL;
}
