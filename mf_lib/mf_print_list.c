#include "mf_list.h"
#include <stdio.h>

void mf_print_list(t_list *begin_list);
void mf_print_list_strs(t_list *begin_list);

void mf_print_list(t_list *begin_list)
{
	t_list  *current;
	int		i;

	printf("\n<<<<<<<<<<<<<<< THE LIST >>>>>>>>>>>>>>>\n");
	if (!begin_list)
		printf("<empty list>\n");
	else
	{
		i = 1;
		current = begin_list;
		while(current)
		{
			printf(" %i) adr: %p || data: %i\n", i++, current, *(int*)current -> data);
			current = current -> next;
		}
	}
	printf("<<<<<<<<<<<<<<< THE  END >>>>>>>>>>>>>>>\n\n");
}

void mf_print_list_strs(t_list *begin_list)
{
	t_list  *current;
	int		i;

	printf("\n<<<<<<<<<<<<<<< THE LIST >>>>>>>>>>>>>>>\n");
	if (!begin_list)
		printf("<empty list>\n");
	else
	{
		i = 1;
		current = begin_list;
		while(current)
		{
			printf(" %i) adr: %p || data: %s\n", i++, current, (char*)current -> data);
			current = current -> next;
		}
	}
	printf("<<<<<<<<<<<<<<< THE  END >>>>>>>>>>>>>>>\n\n");
}