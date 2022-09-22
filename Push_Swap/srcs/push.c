/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:45 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/22 16:13:44 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_dllist *list, t_node *node)
{
	if (list->size == 0)
	{
		node->prev = node;
		node->next = node;
		list->top = node;
		list->bottom = node;
	}
	else
	{
		node->next = list->top;
		node->prev = list->bottom;
		list->top->prev = node;
		list->bottom->next = node;
		list->top = node;
	}
	list->size += 1;
}

t_node	*pop(t_dllist *list)
{
	t_node	*temp;

	if (list->size == 0)
		return (NULL);
	temp = list->top;
	if (list->size == 1)
	{
		list->size = 0;
		list->top = NULL;
		list->bottom = NULL;
	}
	else
	{
		list->top = list->top->next;
		list->top->prev = list->bottom;
		list->bottom->next = list->top;
		list->size -= 1;
	}
	// list->size -= 1;
	return (temp);
}

void	pa(t_lists *lists)
{
	t_node	*node;

	node = pop(lists->b);
	if (!node)
		return ;
	push(lists->a, node);
	write(1, "pa\n", 3);
}

void	pb(t_lists *lists)
{
	t_node	*node;

	node = pop(lists->a);
	if (!node)
		return ;
	push(lists->b, node);
	write(1, "pb\n", 3);
}
