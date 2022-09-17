#include "../includes/push_swap.h"

#include <stdio.h>
void	print_node(t_list *list);

int	main(void)
{
	t_lists	*lists;

	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;

	lists = (t_lists *)malloc(sizeof(t_lists));

	lists->a = (t_list *)malloc(sizeof(t_list));
	lists->a->size = 0;
	lists->a->top = NULL;
	lists->a->bottom = NULL;

	lists->b = (t_list *)malloc(sizeof(t_list));
	lists->b->size = 0;
	lists->b->top = NULL;
	lists->b->bottom = NULL;

	node1 = init_node(2);
	node1->index = 1;
	node2 = init_node(4);
	node2->index = 3;
	node3 = init_node(1);
	node3->index = 0;
	node4 = init_node(3);
	node4->index = 2;

	push(lists->b, node1);
	rotate(lists->b);
	push(lists->b, node2);
	rotate(lists->b);
	push(lists->b, node3);
	rotate(lists->b);
	push(lists->b, node4);
	rotate(lists->b);

	print_node(lists->b);

	b_to_a(lists);

	print_node(lists->a);

	return (0);
}

void	print_node(t_list *list)
{
	int	size;

	size = list->size;
	while (size)
	{
		printf("%d -> ", list->top->num);
		list->top = list->top->next;
		size--;
	}
	printf("\n");
}