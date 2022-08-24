#include "ft_list.h"
#include <stdio.h>

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*current_list1;
	t_list	*current_list2;
	t_list	*prev_list1;
	t_list	*new_elem;

	current_list1 = *begin_list1;
	current_list2 = begin_list2;
	prev_list1 = NULL;
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (current_list1 && current_list2)
	{
		if ((*cmp)(current_list1 -> data, current_list2 -> data) > 0)
		{
			new_elem = current_list2;
			current_list2 = current_list2 -> next;
			if (current_list1 == *begin_list1)
			{
				*begin_list1 = new_elem;
				new_elem -> next = current_list1;
			}
			else
			{
				prev_list1 -> next = new_elem;
				new_elem -> next = current_list1;
			}
				current_list1 = new_elem;
		}
		prev_list1 = current_list1;
		current_list1 = current_list1 -> next;
	}
	if (!current_list1)
		prev_list1 -> next = current_list2;
}
