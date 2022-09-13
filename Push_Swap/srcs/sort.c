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
	if (lists->a->size == 2)
		sort_two_node(lists);
	else if (lists->a->size == 3)
		sort_three_node(lists);
	else if (lists->a->size == 4)
		sort_four_node(lists);
}

void	sort_two_node(t_lists *lists)
{
	sa(lists);
}

void	sort_three_node(t_lists *lists)
{
	int	first;
	int	second;
	int	third;

	first = lists->a->top->num;
	second = lists->a->top->next->num;
	third = lists->a->top->next->next->num;

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

void	sort_four_node(t_lists *lists)
{
	
}
