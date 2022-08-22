#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*p;
	unsigned int	i;

	p = begin_list;
	i = 0;
	if (!p)
		return (NULL);
	while(p)
	{
		if(i == nbr)
			return (p);
		if(i > nbr)
			return (NULL);
		p = p -> next;
		++i;
	}
	return (NULL);
}
