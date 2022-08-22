#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data);

void ft_list_push_back(t_list **begin_list, void *data)
{
	if(!*begin_list)
		*begin_list = ft_create_elem(data);
	else
		ft_list_last(*begin_list) -> next = ft_create_elem(data);
}
