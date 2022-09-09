/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:04:51 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/09 16:32:10 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_lists	*lists;

	if (argc < 2)
		return (0);
	lists = (t_lists *)malloc(sizeof(t_lists));
	if (!lists)
		return (0);
	init_list();
	//input format 확인
	check_input(argc, argv);
	//sorted 되었는지 확인
	if (check_sorted(lists->a))
		//정렬 x 일 경우 -> sort list
		sort_list(lists);
	else
		return ;
}

void	init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return ;
	list->size = 0;
	list->top = NULL;
	list->bottom = NULL;
}

t_node	*init_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int	check_sorted(t_list *list)
{
	while (list->top)
	{
		if (list->top->num >= list->top->next->num)
			return (0);
		list->top = list->top->next;
	}
	return (1);
}
