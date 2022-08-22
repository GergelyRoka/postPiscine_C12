#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *));

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*p;

	p = begin_list;
	while (p)
	{
		(*f)(p -> data);
		p = p -> next;
	}
}
