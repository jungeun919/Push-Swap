/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:38:33 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/17 16:32:37 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_to_b(t_lists *lists)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = 5;
	if (lists->a->top->index <= i)
	{
		pb(lists);
		i++;
	}
	else if (lists->a->top->index > i && lists->a->top->index <= i + chunk)
	{
		pb(lists);
		rb(lists);
		i++;
	}
	else
	{
		if (i < lists->a->size / 2)
			rra(lists);
		else
			ra(lists);
		i++;
	}
}

void	b_to_a(t_lists *lists)
{
	int		i;
	int		size;
	int		max_index;
	t_node	*temp;

	i = 0;
	size = lists->b->size;
	while (size)
	{
		max_index = lists->b->size - 1;
		temp = lists->b->top;
		while (temp->index != max_index)
		{
			temp = temp->next;
			i++;
		}
		if (i < lists->b->size / 2)
			while (lists->b->top != temp)
				rb(lists);
		else
			while (lists->b->top != temp)
				rrb(lists);
		pa(lists);
		size--;
	}
}
