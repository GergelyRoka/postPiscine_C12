#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*prev;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		if( (*cmp)(current -> data, data_ref) == 0)
		{
			(*free_fct)(current -> data);
			if(prev)
			{
				prev -> next = current -> next;
				free(current);
				current = prev -> next;
			}
			else
			{
				*begin_list = current -> next;
				free(current);
				current = *begin_list;
			}
		}
		else
		{
			prev = current;
			current = current -> next;
		}
	}
}
