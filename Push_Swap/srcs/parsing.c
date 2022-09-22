/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:07:26 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/22 15:38:11 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_input(char **argv, t_lists *lists)
{
	// printf("check_input\n");
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			split_input(argv[i], lists);
		// printf("split_input\n");

		}
		else
		{
			check_valid_input_and_push(argv[i], lists);
			// printf("check_valid_input_and_push\n");
		}
		// printf("check ok : %s\n", argv[i]);
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

long long	atoll(const char *str)
{
	// printf("atoll\n");

	
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
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
	// printf("check_duplicate_and_indexing\n");

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
	// printf("check_duplicate_and_indexing2\n");
	return (1);
}
