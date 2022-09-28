/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:32:34 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/28 19:39:00 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	atoll(const char *str)
{
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
		if (!str[i])
			print_error();
	}
	return (check_num(str, i, sign));
}

long long	check_num(const char *str, int i, int sign)
{
	long long	num;

	num = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			num = num * 10 + str[i] - '0';
			if (sign * num < -2147483648 || sign * num > 2147483647)
				print_error();
		}
		else
			print_error();
		i++;
	}
	return (sign * num);
}
