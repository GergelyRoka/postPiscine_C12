#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	switch_elements(t_list **begin_list, t_list *target);

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*p;
	t_list	*end;

	p = *begin_list;
	end = NULL;
	while (*begin_list != end)
	{
		while (p -> next != end)
		{
			if ((*cmp)(p -> data, p -> next -> data) > 0)
				switch_elements(begin_list, p);
			else
				p = p -> next;
		}
		end = p;
		p = *begin_list;
	}
}

void	switch_elements(t_list **begin_list, t_list *target)
{
	t_list	*p;
	t_list	*target2;

	p = *begin_list;
	if (p == target)
	{
		target2 = target -> next;
		*begin_list = target2;
		target -> next = target2 -> next;
		target2 -> next = target;
	}
	else
	{
		while (p -> next != target)
			p = p -> next;
		target2 = target -> next;
		target -> next = target2 -> next;
		target2 -> next = target;
		p -> next = target2;
	}
} 