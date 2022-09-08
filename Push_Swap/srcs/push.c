/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:45 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/08 16:22:51 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list *list, t_node *node)
{
	if (list->size == 0)
	{
		node->prev = NULL;
		node->next = NULL;
		list->top = node;
		list->bottom = node;
	}
	else
	{
		node->next = list->top;
		node->prev = NULL;
		list->top = node;
	}
	list->size += 1;
}

t_node	*pop(t_list *list)
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
		list->top = list->top->next;
	return (temp);
}

void	pa(t_lists *lists)
{
	t_node	*node;

	node = pop(lists->b);
	if (!node)
		return ;
	push(lists->a, node);
}

void	pb(t_lists *lists)
{
	t_node	*node;

	node = pop(lists->a);
	if (!node)
		return ;
	push(lists->b, node);
}