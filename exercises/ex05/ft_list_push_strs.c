#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	int		i;

	begin_list = NULL;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&begin_list, *strs);
		strs++;
		i++;
	}
	return (begin_list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*element;

	if((element = ft_create_elem(data)))
	{
		element -> next = *begin_list;
		*begin_list = element;
	}
}
