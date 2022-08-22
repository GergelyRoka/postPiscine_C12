#include "ft_list.h"
#include "mf_list.h"

t_list	*mf_make_list_random_numbers(int n)
{
	t_list	*begin_list;
	int		i;
	int		*data;

	srand(time(NULL));
	begin_list = NULL;
	i = 0;
	while(i < n)
	{
		data = malloc(sizeof(int));
		*data = rand() % 100;
		ft_list_push_front(&begin_list, data);
		++i;
	}
}