#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;

	if((last = ft_list_last(*begin_list)))
		last -> next = ft_create_elem(data);
	else
		*begin_list = ft_create_elem(data);
}

t_list	*ft_list_last(t_list *begin_list)
{
	if(!begin_list)
		return (begin_list);
	while(begin_list -> next)
		begin_list = begin_list -> next;
	return (begin_list);
}