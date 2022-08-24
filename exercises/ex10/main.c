/*
Data of elements is integer.
foobool():   ff data > 50
foo():       data will be reducated by 50
*/

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define NUM_HASH 66

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
void	foo(void * n);
int		foobool(void *data, void* ref);
void	test_case(t_list *head_of_list, int *ref, unsigned int size, char *msg);
t_list	*ft_create_elem(void *data);
void	print_list(t_list *begin_list);
void	push_front_random_elems(t_list **begin_list, unsigned int n);
void	push_random(t_list **begin_list);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

int	main(void)
{
	t_list	*head_of_list;
	int		*ref;

	head_of_list = NULL;
	if(!(ref = malloc(sizeof(int))))
		return (0);
	*ref = 50;
	srand(time(NULL));
	test_case(head_of_list, ref, 0, "TEST00-empty");
	test_case(head_of_list, ref, 1, "TEST01-monad");
	test_case(head_of_list, ref, 2, "TEST01-duad");
	test_case(head_of_list, ref, 5, "TEST01-pentad");
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

void	foo(void * n)
{
	if((*(int*)n = *(int*)n - 50))
		printf("data is %i, after -50 it is %i\n", *(int*)n + 50, *(int*)n);
	else
		printf("Maybe the cast of *(int*) doesn't work on the data (%p).\n", n);
}

int	foobool(void *data, void* ref)
{
	if(*(int*)data > *(int*)ref)
		return (0);
	return (1);
}

void print_hashtag(unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i++ < n)
		printf("#");
	printf("\n");
}

void	test_case(t_list *head_of_list, int *ref, unsigned int size, char *msg)
{
	print_hashtag(NUM_HASH);
	printf("###_START_%s_",msg);
	print_hashtag(NUM_HASH-strlen(msg) - 11);
	push_front_random_elems(&head_of_list, size);
	print_list(head_of_list);
	printf("Beggining of ft_list_foreach_if().\n----------------------------------\n");
	ft_list_foreach_if(head_of_list, foo, ref, foobool);
	printf("----------------------------------\nEnd of ft_list_foreach_if().\n");
	print_list(head_of_list);	
	ft_list_clear(head_of_list, free);
	printf("###_END_%s_",msg);
	print_hashtag(NUM_HASH - strlen(msg) - 9);
	print_hashtag(NUM_HASH);
}
