#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	ft_list_sort(t_list **begin_list, int (*cmp)());

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

t_list	*_make_list_rand_nums(unsigned int size);
void	_print_list(t_list *head, char *msg);
int		_cmp_integers(void *n1, void *n2);


int	main(void)
{
	t_list *head;

	srand(time(NULL));
	{
		head = _make_list_rand_nums(7);
		_print_list(head, "The list");
		ft_list_sort(&head, _cmp_integers);
		_print_list(head, "The sorted list");
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
			printf("  %i) adr: %p || next: %p || data: %i\n", i++, head, head -> next, *(int*)head -> data);
			head = head -> next;
		}
	}
	printf("\n");
}

int	_cmp_integers(void *n1, void *n2)
{
	return (*(int*)n1 > *(int*)n2);
}