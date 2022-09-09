/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:07:46 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/09 13:07:48 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list *list)
{
	if (list->size < 2)
		return ;
	list->top = list->top->next;
	list->bottom = list->bottom->next;
}

void	ra(t_lists *lists)
{
	rotate(lists->a);
}

void	rb(t_lists *lists)
{
	rotate(lists->b);
}

void	rr(t_lists *lists)
{
	rotate(lists->a);
	rotate(lists->b);
}
