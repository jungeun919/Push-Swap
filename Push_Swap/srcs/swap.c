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
	t_node	*temp1;
	t_node	*temp2;

	if (list->size < 2)
		return ;
	temp1 = list->top;
	temp2 = list->top->next;
	temp1->next = temp2->next;
	temp1->prev = temp2;
	if (temp1->next)
		temp1->next->prev = temp1;
	else
		list->bottom = temp2;
	temp2->prev = list->bottom;
	temp2->next = temp1;
	list->top = temp2;
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
