/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:01:19 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/14 07:59:57 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //exit, malloc, free
# include <unistd.h> //read, close

typedef struct s_node
{
	int				num;
	int				index;
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

//push_swap.c
void	init_list(void);
t_node	*init_node(int num);
int		check_sorted(t_list *list);
void	print_error(void);

//swap.c
void	swap(t_list *list);
void	sa(t_lists *lists);
void	sb(t_lists *lists);
void	ss(t_lists *lists);

//push.c
void	push(t_list *list, t_node *node);
t_node	*pop(t_list *list);
void	pa(t_lists *lists);
void	pb(t_lists *lists);

//rotate.c
void	rotate(t_list *list);
void	ra(t_lists *lists);
void	rb(t_lists *lists);
void	rr(t_lists *lists);

//reverse_rotate.c
void	reverse_rotate(t_list *list);
void	rra(t_lists *lists);
void	rrb(t_lists *lists);
void	rrr(t_lists *lists);

//free.c
void	free_list(t_list *list);
void	free_lists(t_lists *lists);

#endif
