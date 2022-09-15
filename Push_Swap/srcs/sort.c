/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:57:50 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/14 08:38:23 by jungchoi         ###   ########.fr       */
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

void	sort_two_node(t_lists *lists)
{
	if (lists->a->top->index > lists->a->top->next->index)
		sa(lists);
}

void	sort_three_node(t_lists *lists)
{
	int	first;
	int	second;
	int	third;

	first = lists->a->top->index;
	second = lists->a->top->next->index;
	third = lists->a->top->next->next->index;

	if (first < second)
	{
		if (second > third) //132
		{
			rra(lists);
			sa(lists);
		}
		else //231
			rra(lists);
	}
	else
	{
		if (second < third && first < third) //213
			sa(lists);
		else if (second < third && first > third) //312
			ra(lists);
		else if (second > third) //321
		{
			ra(lists);
			sa(lists);
		}
	}
}

void	sort_four_or_five_node(t_lists *lists)
{
	while (lists->a->size > 3)
	{
		if (lists->a->top->index < 2)
			pb(lists);
		else
			ra(lists);
	}
	sort_three_node(lists);
	while (lists->b->size)
		pa(lists);
	if (lists->a->top->index != 0)
		sa(lists);
}
