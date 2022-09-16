/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:57:50 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/16 16:53:05 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_list(t_lists *lists)
{
	if (lists->a->size <= 5)
		sort_under_five(lists);
	else
		sort_over_five(lists);
}

void	sort_under_five(t_lists *lists)
{
	if (lists->a->size < 2)
		return ;
	else if (lists->a->size == 2)
		sort_two_node(lists);
	else if (lists->a->size == 3)
		sort_three_node(lists);
	else
		sort_four_or_five_node(lists);
}

void	sort_over_five(t_lists *lists)
{
	a_to_b(lists);
	b_to_a(lists);
}

int	check_sorted(t_list *list)
{
	while (list->size)
	{
		if (list->top->index > list->top->next->index)
			return (0);
		list->top = list->top->next;
	}
	return (1);
}
