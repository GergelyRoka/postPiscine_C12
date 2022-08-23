#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list	*ft_create_elem(void *data);
void	print_list(t_list *begin_list);
void	print_elem(t_list *elem);
void	push_front_random_elems(t_list **begin_list, unsigned int n);
void	push_random(t_list **begin_list);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

int	main(void)
{
	t_list	*head_of_list;

	head_of_list = NULL;
	srand(time(NULL));
	print_list(head_of_list);
	printf("### TEST #01 - empty list, 3rd element\n");
	print_elem(ft_list_at(head_of_list, 2));
	push_front_random_elems(&head_of_list, 5);
	print_list(head_of_list);
	printf("### TEST #02 - elems of 5, 1st element\n");
	print_elem(ft_list_at(head_of_list, 0));
	printf("### TEST #03 - elems of 5, 3rd element\n");
	print_elem(ft_list_at(head_of_list, 2));
	printf("### TEST #04 - elems of 5, 5th element\n");
	print_elem(ft_list_at(head_of_list, 4));
	printf("### TEST #05 - elems of 5, 7th element\n");
	print_elem(ft_list_at(head_of_list, 6));
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

void	print_elem(t_list *elem)
{
	if(elem)
		printf("  adr:\t%p\n  data:\t%i\n\n", elem, *(int*)elem -> data);
	else
		printf("  There is no element on that place.\n\n");
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

void	push_front_random_elems(t_list **begin_list, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		push_random(begin_list);
		++i;
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
