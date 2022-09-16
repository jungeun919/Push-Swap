/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:07:26 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/16 16:52:03 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input(char **argv, t_lists *lists)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			split_input(argv[i], lists);
		else
			check_valid_input(argv[i], lists);
		i++;
	}
	return (0);
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
		check_valid_input(split[i], lists);
		free(split[i]);
		i++;
	}
	free(split);
}

long long	atoll(const char *str)
{
	int			i;
	int			sign;
	long long	num;
	
	i = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		if (sign * num < -2147483648 || sign * num > 2147483647)
			print_error();
		i++;
	}
	return (sign * num);
}

void	check_valid_input_and_push(char *str, t_lists *lists)
{
	long long	num;
	t_node		*node;
	
	num = atoll(str);
	node = init_node((int)num);
	if (!(check_duplicate_and_indexing(lists->a, node)))
		print_error();
	push(lists->a, node);
	rotate(lists->a);
}

int	check_duplicate_and_indexing(t_list *list, t_node *node)
{
	t_node	*temp;

	temp = list->top;
	while (list->size)
	{
		if (temp->num == node->num)
			return (0);
		if (temp->num < node->num)
			node->index++;
		else if (temp->num > node->num)
			temp->index++;
		temp = temp->next;
	}
	return (1);
}
