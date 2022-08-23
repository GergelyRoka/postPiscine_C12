/*
ex05
Testing t_list	*ft_list_push_strs(int size, char **strs);
*/
#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs);
t_list	*ft_create_elem(void *data);
void	print_list(t_list *begin_list);
void	list_links_free(t_list *begin_list);

int main(int argc, char **argv)
{
	t_list	*head_of_list;

	head_of_list = NULL;
	if (argc > 1)
	{
		argv++;
		head_of_list = ft_list_push_strs(argc-1, argv);
	}
	printf("\nList created from arguments of the main() in reversed order:");
	//example: ./a.out 1 2 asd  list: asd 2 1
	print_list(head_of_list);
	list_links_free(head_of_list);
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
			printf(" %i) adr: %p || data: %s\tnext: %p\n", i++, current, (char*)current -> data, current -> next);
			current = current -> next;
		}
	}
	printf("<<<<<<<<<<<<<<<<<<<<<<<<< THE  END >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

void	list_links_free(t_list *begin_list)
{
	t_list	*dead_one;
	while (begin_list)
	{
		dead_one = begin_list;
		begin_list = begin_list -> next;
		dead_one -> next = NULL;
		free(dead_one);
	}
}
