/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:07:26 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/23 14:32:44 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_input(char **argv, t_lists *lists)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			split_input(argv[i], lists);
		else
			check_valid_input_and_push(argv[i], lists);
		i++;
	}
}

void	split_input(char *str, t_lists *lists)
{
	int		i;
	char	**split;

	split = ft_split(str, ' ');
	if (!split)
		print_error();
	i = 0;
	while (split[i])
	{
		check_valid_input_and_push(split[i], lists);
		free(split[i]);
		i++;
	}
	free(split);
}

void	check_valid_input_and_push(char *str, t_lists *lists)
{
	long long	num;
	t_node		*node;

	num = atoll(str);
	if (num < -2147483648 || num > 2147483647)
		print_error();
	node = init_node((int)num);
	if (!(check_duplicate_and_indexing(lists->a, node)))
		print_error();
	push(lists->a, node);
	rotate(lists->a);
}

int	check_duplicate_and_indexing(t_dllist *list, t_node *node)
{
	int		size;
	t_node	*temp;

	size = list->size;
	temp = list->top;
	while (size)
	{
		if (temp->num == node->num)
			return (0);
		if (temp->num < node->num)
			node->index++;
		else if (temp->num > node->num)
			temp->index++;
		temp = temp->next;
		size--;
	}
	return (1);
}
