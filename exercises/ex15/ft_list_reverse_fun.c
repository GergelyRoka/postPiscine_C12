//Timoti's code

#include "ft_list.h"
#include <stdio.h>

void	ft_swap_nodes(t_list *a, t_list *b)
{
	t_list	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tail;
	t_list	*cursor;
	t_list	*previous;
	t_list	*next;

	if (!begin_list || !begin_list->next)
		return ;
	tail = begin_list->next;
	while (tail->next)
		tail = tail->next;
	ft_swap_nodes(begin_list, tail);
	cursor = tail;
	previous = 0;
	while (cursor->next != tail)
	{
		next = cursor->next;
		cursor->next = previous;
		previous = cursor;
		cursor = next;
	}
	cursor->next = previous;
	begin_list->next = cursor;
}
