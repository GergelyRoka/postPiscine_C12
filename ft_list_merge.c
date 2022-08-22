#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2);

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if(*begin_list1)
		ft_list_last(*begin_list1) -> next = begin_list2;
	else
		*begin_list1 = begin_list2;
}
