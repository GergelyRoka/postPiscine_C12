#include "ft_list.h"

int ft_list_size(t_list *begin_list);

int ft_list_size(t_list *begin_list)
{
	t_list	*p;
	int		size;

	if (!begin_list)
		return (0);
	p = begin_list;
	size = 0;
	while(p)
	{
		p = p ->next;
		++size;
	}
	return (size);
}