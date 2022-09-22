/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:01:19 by jungchoi          #+#    #+#             */
/*   Updated: 2022/09/22 14:03:49 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <stdlib.h> //exit, malloc, free
# include <unistd.h> //read, close

# include <stdio.h> //지우기

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_dllist
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_dllist;

typedef struct s_lists
{
	struct s_dllist	*a;
	struct s_dllist	*b;
}	t_lists;

//push_swap.c
t_dllist	*init_list(void);
t_node		*init_node(int num);
void		print_error(void);

//swap.c
void		swap(t_dllist *list);
void		sa(t_lists *lists);
void		sb(t_lists *lists);
void		ss(t_lists *lists);

//push.c
void		push(t_dllist *list, t_node *node);
t_node		*pop(t_dllist *list);
void		pa(t_lists *lists);
void		pb(t_lists *lists);

//rotate.c
void		rotate(t_dllist *list);
void		ra(t_lists *lists);
void		rb(t_lists *lists);
void		rr(t_lists *lists);

//reverse_rotate.c
void		reverse_rotate(t_dllist *list);
void		rra(t_lists *lists);
void		rrb(t_lists *lists);
void		rrr(t_lists *lists);

//free.c
void		free_list(t_dllist *list);
void		free_lists(t_lists *lists);

//parsing.c
void		check_input(char **argv, t_lists *lists);
void		split_input(char *str, t_lists *lists);
long long	atoll(const char *str);
void		check_valid_input_and_push(char *str, t_lists *lists);
int			check_duplicate_and_indexing(t_dllist *list, t_node *node);

//sort.c
void		sort_list(t_lists *lists);
void		sort_under_five(t_lists *lists);
void		sort_over_five(t_lists *lists);
int			check_sorted(t_dllist *list);

//sort_under_five.c
void		sort_two_node(t_lists *lists);
void		sort_three_node(t_lists *lists);
void		sort_three_node_index(t_lists *lists, \
			int first, int second, int third);
void		sort_four_or_five_node(t_lists *lists);

//sort_over_five.c
int			get_chunk(t_dllist *list);
void		a_to_b(t_lists *lists, int chunk);
void		b_to_a(t_lists *lists);

//debug.c
void		print_node(t_dllist *list);

#endif
