/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:13:29 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/09 13:13:31 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_dllist *list)
{
	if (list->size < 2)
		return ;
	list->top = list->top->prev;
	list->bottom = list->bottom->prev;
}

void	rra(t_lists *lists)
{
	reverse_rotate(lists->a);
	write(1, "rra\n", 4);
}

void	rrb(t_lists *lists)
{
	reverse_rotate(lists->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_lists *lists)
{
	reverse_rotate(lists->a);
	reverse_rotate(lists->b);
}
