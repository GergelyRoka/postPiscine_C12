#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *dead_one;

	while(begin_list)
	{
		dead_one = begin_list;
		begin_list = begin_list -> next;
		free_fct(dead_one -> data);
		free(dead_one);
		dead_one = NULL;
	}
}
