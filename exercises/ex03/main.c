#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	ft_list_push_front(t_list **begin_list, void *data);
void	print_list(t_list *begin_list);
void	push_random(t_list **begin_list);
t_list	*ft_list_last(t_list *begin_list);

int	main(void)
{
	t_list	*head_of_list;
	int		i;

	head_of_list = NULL;
	i = 0;
	srand(time(NULL));
	print_list(head_of_list);
	printf("The address of the last element: %p\n", ft_list_last(head_of_list));
	while (i < 3)
	{
		push_random(&head_of_list);
		++i;
	}
	print_list(head_of_list);
	printf("The address of the last element: %p\n", ft_list_last(head_of_list));
	return (0);
}

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	if(!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem -> next = NULL;
	elem -> data = data;
	return (elem);
}

void print_list(t_list *begin_list)
{
	t_list	*current;
	int		i;

	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<< THE LIST >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	if (!begin_list)
		printf("<empty list>\n");
	else
	{
		i = 1;
		current = begin_list;
		while(current)
		{
			printf(" %i) adr: %p || data: %i\tnext: %p\n", i++, current, *(int*)current -> data, current -> next);
			current = current -> next;
		}
	}
	printf("<<<<<<<<<<<<<<<<<<<<<<<<< THE  END >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

void	push_random(t_list **begin_list)
{
	int	*int_data;

	if(!(int_data = malloc(sizeof(int))))
		printf("<<ERROR :: memory not allocated for int *int_data>>\n");
	else
	{
		*int_data = rand() % 100;
		ft_list_push_front(begin_list, int_data);
	}
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
