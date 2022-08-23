#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	ft_list_push_front(t_list **begin_list, void *data);
void	print_list(t_list *begin_list);
void	push_n_print(t_list **begin_list, int i);

int	main(int argc, char const *argv[])
{
	t_list	*head_of_list;
	int		i;

	head_of_list = NULL;
	i = 0;
	srand(time(NULL));
	print_list(head_of_list);
	while (i < 5)
		push_n_print(&head_of_list, ++i);
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
	printf("<<<<<<<<<<<<<<<<<<<<<<<<< THE  END >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
}

void	push_n_print(t_list **begin_list, int i)
{
	int	*int_data;

	if(!(int_data = malloc(sizeof(int))))
		printf("<<ERROR :: memory not allocated for int *int_data>>\n");
	else
	{
		*int_data = rand() % 100;
		printf("PUSH: %i\n", *int_data);
		ft_list_push_front(begin_list, int_data);
		print_list(*begin_list);
	}
}
