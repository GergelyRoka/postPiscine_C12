#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list);

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	if (*begin_list)
	{
		prev = NULL;
		current = *begin_list;
		while(current)
		{
			next = current -> next;
			current -> next = prev;
			prev = current;
			current = next;
		}
		*begin_list = prev;
	}
}
