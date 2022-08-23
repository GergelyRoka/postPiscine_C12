#include "tests.h"
//#include "../mf_lib/mf_list.h"
//#include "../ft_lib/ft_list.h"

int cm(void *data, void *ref);

void test_for2()
{
	t_list	*begin_list;
	int		*ref;

	ref = malloc(sizeof(int));
	*ref = 49;

	begin_list = mf_make_list_random_numbers(20);
	ft_list_remove_if(&begin_list, ref, cm, free);

	mf_print_list(begin_list);

	free(ref);
	ft_list_clear(begin_list, free);


	
}

int cm(void *data, void *ref)
{
	return (*(int*)data > *(int*)ref);
}
