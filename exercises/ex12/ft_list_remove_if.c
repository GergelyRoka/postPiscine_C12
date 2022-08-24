#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*dead_one;
	t_list	*current;

	while (*begin_list && !cmp((*begin_list) -> data, data_ref))
	{
		dead_one = *begin_list;
		*begin_list = (*begin_list) -> next;
		free_fct(dead_one -> data);
		dead_one -> next = NULL;
		free(dead_one);
	}
	current = *begin_list;
	while (current && current -> next)
	{
		if (!cmp(current -> next -> data, data_ref))
		{
			dead_one = current -> next;
			current -> next = current -> next -> next;
			free_fct(dead_one -> data);
			dead_one -> next = NULL;
			free(dead_one);
		}
		else
			current = current -> next;
	}
}
