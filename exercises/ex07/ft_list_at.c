#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list && i <= nbr)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list -> next;
		i++;
	}
	return (NULL);
}
