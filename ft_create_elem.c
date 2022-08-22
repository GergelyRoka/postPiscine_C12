#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

t_list	*ft_create_elem(void *data)
{
	t_list	*element;

	if(!(element = malloc(sizeof(t_list))))
		return (0);
	element -> next = NULL;
	element -> data = data;
	return (element);
}
