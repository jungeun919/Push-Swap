#include "../includes/push_swap.h"

void	print_node(t_dllist *list)
{
	int		size;
	t_node	*init_top;

	size = list->size;
	init_top = list->top;
	while (size)
	{
		printf("%d -> ", list->top->num);
		list->top = list->top->next;
		size--;
	}
	printf("\n");
	list->top = init_top;
}
