#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		if ((*cmp)(current -> data, data) > 0)
		{
			if (current != *begin_list)
			{
				prev -> next = ft_create_elem(data);
				prev -> next -> next = current;
			}
			else
			{
				*begin_list = ft_create_elem(data);
				(*begin_list) -> next = current;
			}
			return ;
		}
		prev = current;
		current = current -> next;
	}
	if (prev)
		prev -> next = ft_create_elem(data);
	else
		*begin_list = ft_create_elem(data);
}
