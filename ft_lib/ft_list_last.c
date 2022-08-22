#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list);

t_list *ft_list_last(t_list *begin_list)
{
	t_list *p;

	if (!begin_list)
		return (begin_list);
	p = begin_list;
	while (p -> next)
		p = p -> next;
	return (p);
}
