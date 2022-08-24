#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());

t_list	*_make_list_rand_nums(unsigned int size);
void	_print_list(t_list *head, char *msg);
int		_cmp_integers(void *n1, void *n2);
void	_insert_number(t_list **head, int n);
void	_insert_n_rnd_numbers(t_list **head, int n);


int	main(void)
{
	t_list	*head;
	t_list	*head2;

	srand(time(NULL));
	{
		head = NULL;
		head2 = NULL;
		_insert_n_rnd_numbers(&head, 0);
		_insert_n_rnd_numbers(&head2, 3);
		_print_list(head, "\nFirst list");
		_print_list(head2, "Second list");
		ft_sorted_list_merge(&head, head2, _cmp_integers);
		_print_list(head, "First list after merge");
	}
	{
		head2 = NULL;
		_insert_n_rnd_numbers(&head2, 0);
		_print_list(head2, "Empty second list");
		ft_sorted_list_merge(&head, head2, _cmp_integers);
		_print_list(head, "First list after merge");
	}
	{
		head2 = NULL;
		_insert_n_rnd_numbers(&head2, 4);
		_print_list(head2, "New second list");
		ft_sorted_list_merge(&head, head2, _cmp_integers);
		_print_list(head, "First list after merge");
	}
	ft_list_clear(head, free);
	return 0;
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		if ((*cmp)(current -> data, data) > 0)
		{
			if (current != *begin_list)
			{
				prev -> next = ft_create_elem(data);
				prev -> next -> next = current;
			}
			else
			{
				*begin_list = ft_create_elem(data);
				(*begin_list) -> next = current;
			}
			return ;
		}
		prev = current;
		current = current -> next;
	}
	if (prev)
		prev -> next = ft_create_elem(data);
	else
		*begin_list = ft_create_elem(data);
}

t_list	*_make_list_rand_nums(unsigned int size)
{
	t_list			*head;
	t_list			*new_elem;
	int				*data;
	unsigned int	i;
	
	head = NULL;
	i = 0;
	while (i < size)
	{
		if (!(data = malloc(sizeof(int))))
			break;
		*data = rand() % 100;
		if (!(new_elem = ft_create_elem(data)))
		{
			free(data);
			break;
		}
		if(head)
			new_elem -> next = head;
		head = new_elem;
		i++;
	}
	return (head);
}

void	_print_list(t_list *head, char *msg)
{
	unsigned int	i;

	printf("%s\n",msg);
	if (!head)
		printf("<empty list>\n");
	else
	{
		i = 1;
		while (head)
		{
			printf("  %i)\tadr: %p || next: %p || data: %i\n", i++, head, head -> next, *(int*)head -> data);
			head = head -> next;
		}
	}
	printf("\n");
}

int	_cmp_integers(void *n1, void *n2)
{
	return (*(int*)n1 > *(int*)n2);
}

void	_insert_number(t_list **head, int n)
{
	int		*new_number;
	
	if(!(new_number = malloc(sizeof(int))))
	{
		printf("Error with malloc.\n");
		return ;
	}
	*new_number = n;
	ft_sorted_list_insert(head, new_number, _cmp_integers);
}

void	_insert_n_rnd_numbers(t_list **head, int n)
{
	while (n-- > 0)
		_insert_number(head, rand() % 100);
}
