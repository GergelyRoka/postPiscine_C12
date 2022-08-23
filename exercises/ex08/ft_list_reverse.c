#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}
