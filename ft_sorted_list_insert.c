#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;

	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else if((*cmp)((prev = ft_list_last(*begin_list)) -> data, data) <= 0)
		prev -> next = ft_create_elem(data);
	else
	{
		current = *begin_list;
		prev = NULL;
		while (current)
		{
			if ((*cmp)(current -> data, data) > 0)
			{
				if (!prev)
					(*begin_list = ft_create_elem(data)) -> next = current;
				else
					(prev -> next = ft_create_elem(data)) -> next = current;
				current = NULL;
			}
			else
				(prev = current) && (current = current -> next);
		}
	}
}