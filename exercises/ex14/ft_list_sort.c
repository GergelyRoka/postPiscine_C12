#include "ft_list.h"
#include <stdlib.h>

void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	_switch_elements(t_list **begin_list, t_list *target);

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*end;

	current = *begin_list;
	end = NULL;
	while (*begin_list != end)
	{
		while (current -> next != end)
		{
			if ((*cmp)(current -> data, current -> next -> data) > 0)
				_switch_elements(begin_list, current);
			else
				current = current -> next;
		}
		end = current;
		current = *begin_list;
	}
}

void	_switch_elements(t_list **begin_list, t_list *target)
{
	t_list	*current;
	t_list	*target2;

	current = *begin_list;
	if (current == target)
	{
		target2 = target -> next;
		*begin_list = target2;
		target -> next = target2 -> next;
		target2 -> next = target;
	}
	else
	{
		while (current -> next != target)
			current = current -> next;
		target2 = target -> next;
		target -> next = target2 -> next;
		target2 -> next = target;
		current -> next = target2;
	}
} 