/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:01:19 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/08 16:43:24 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //exit, malloc, free
# include <unistd.h> //read, close

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_list;

typedef struct s_lists
{
	struct s_list	*a;
	struct s_list	*b;
}	t_lists;

void	init_list(void);
t_node	*init_node(int num);
int		check_sorted(t_list *list);

void	push(t_list *list, t_node *node);
t_node	*pop(t_list *list);
void	pa(t_lists *lists);
void	pb(t_lists *lists);

#endif
