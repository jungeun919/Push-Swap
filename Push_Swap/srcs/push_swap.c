/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:04:51 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/28 15:34:02 by jungchoi         ###   ########.fr       */
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
	lists->a = init_list();
	lists->b = init_list();
	check_input(argc, argv, lists);
	if (!(check_sorted(lists->a)))
		sort_list(lists);
	else
		return (0);
	free_lists(lists);
	return (0);
}

t_dllist	*init_list(void)
{
	t_dllist	*list;

	list = (t_dllist *)malloc(sizeof(t_dllist));
	if (!list)
		return (NULL);
	list->size = 0;
	list->top = NULL;
	list->bottom = NULL;
	return (list);
}

t_node	*init_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
