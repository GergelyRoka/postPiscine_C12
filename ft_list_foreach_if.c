#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*p;

	if (begin_list)
	{
		p = begin_list;
		while (p)
		{
			if ((*cmp)(p -> data, data_ref) == 0)
				(*f)(p -> data);
			p = p -> next;
		}
	}
}
