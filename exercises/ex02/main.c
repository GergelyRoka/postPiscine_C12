#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int		ft_list_size(t_list *begin_list);
void	ft_list_push_front(t_list **begin_list, void *data);
void	print_list(t_list *begin_list);
void	push_random(t_list **begin_list);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

int	main(void)
{
	t_list	*head_of_list;
	int		i;

	head_of_list = NULL;
	i = 0;
	srand(time(NULL));
	print_list(head_of_list);
	while (i < 3)
	{
		push_random(&head_of_list);
		print_list(head_of_list);
		++i;
	}
	ft_list_clear(head_of_list, free);
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

	printf("SIZE of the list: %i", ft_list_size(begin_list));
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

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*dead_one;
	while(begin_list)
	{
		dead_one = begin_list;
		begin_list = begin_list -> next;
		free_fct(dead_one -> data);
		dead_one -> next = NULL;
		free(dead_one);
	}
}
