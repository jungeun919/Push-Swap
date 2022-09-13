/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:37:35 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/09 17:02:18 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *list)
{
	t_node	*temp;

	if (list->size < 2)
		return ;
	temp = list->top->num;
	list->top->num = list->top->next->num;
	list->top->next->num = temp;

	// list->top->next = temp->next;
	// list->top->prev = temp;
	// temp->prev = list->bottom;
	// temp->next = list->top;
}

void	sa(t_lists *lists)
{
	swap(lists->a);
	write(1, "sa\n", 3);
}

void	sb(t_lists *lists)
{
	swap(lists->b);
	write(1, "sb\n", 3);
}

void	ss(t_lists *lists)
{
	swap(lists->a);
	swap(lists->b);
}
