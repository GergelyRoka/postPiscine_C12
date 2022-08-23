#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*element;

	if(element = ft_create_elem(data))
	{
		element -> next = *begin_list;
		*begin_list = element;
	}
}
