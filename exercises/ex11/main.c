#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
int		foobool(void *data, void* ref);
void	test_case(int *ref, unsigned int size);
t_list	*ft_create_elem(void *data);
void	print_list(t_list *begin_list);
void	push_front_random_elems(t_list **begin_list, unsigned int n);
void	push_random(t_list **begin_list);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

int	main(void)
{
	int		*ref;

	srand(time(NULL));
	if(!(ref = malloc(sizeof(int))))
		return (0);
	*ref = 50;
	test_case(ref, 0);
	test_case(ref, 100);
	free(ref);
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

	printf("\nTHE LIST\n");
	if (!begin_list)
		printf("  <empty list>\n");
	else
	{
		i = 1;
		current = begin_list;
		while(current)
		{
			printf("  %i) adr: %p || data: %i\tnext: %p\n", i++, current, *(int*)current -> data, current -> next);
			current = current -> next;
		}
	}
	printf("\n");
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

int	foobool(void *data, void* ref)
{
	if(*(int*)data > *(int*)ref)
		return (0);
	return (1);
}

void	test_case(int *ref, unsigned int size)
{
	t_list	*begin_list;

	begin_list = NULL;
	push_front_random_elems(&begin_list, size);
	print_list(begin_list);
	printf("The adr of the 1st elem which greater than %i: %p\n",*ref, ft_list_find(begin_list, ref, foobool));
	ft_list_clear(begin_list, free);
}
