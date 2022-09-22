#include "../includes/push_swap.h"

int	main(void)
{
	t_lists	*lists;

	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;

	lists = (t_lists *)malloc(sizeof(t_lists));

	lists->a = (t_dllist *)malloc(sizeof(t_dllist));
	lists->a->size = 0;
	lists->a->top = NULL;
	lists->a->bottom = NULL;

	lists->b = (t_dllist *)malloc(sizeof(t_dllist));
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

	push(lists->a, node1);
	rotate(lists->a);
	push(lists->a, node2);
	rotate(lists->a);
	push(lists->a, node3);
	rotate(lists->a);
	push(lists->a, node4);
	rotate(lists->a);

	print_node(lists->a);

	node5 = init_node(5);
	node5->index = 4;
	push(lists->a, node5);
	print_node(lists->a);

	pop(lists->a);
	print_node(lists->a);

	reverse_rotate(lists->a);
	print_node(lists->a);

	rotate(lists->a);
	print_node(lists->a);

	swap(lists->a);
	print_node(lists->a);

	system("leaks a.out");

	return (0);
}
