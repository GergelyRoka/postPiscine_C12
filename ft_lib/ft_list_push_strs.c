#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*p;
	int		i;

	p = NULL;
	i = 0;
	if (size == 0)
		return (NULL);
	while (i < size)
	{
		ft_list_push_front(&p, strs[i]);
		++i;
	}
	return (p);
}