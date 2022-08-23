#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data);

int main(void)
{
	t_list	*element;
	int		*integer_data;

	if(!(integer_data = malloc(sizeof(int))))
	{
		printf("<<ERROR :: memory not allocated>>\n");
		exit (0);
	}
	*integer_data = 42;
	element = ft_create_elem(integer_data);
	if(element)
	{
		printf("element points here:\t%p\n\tnext:\t\t%p\n\t*(int*)data:\t%i\n", element, element -> next, *(int*)element -> data);
		free(element -> data);
		free(element);
	}
	else
	{
		printf("element = %p\n", element);
		free(integer_data);
	}
	return (0);
}
