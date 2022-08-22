#include "ft_lib/ft_list.h"
#include "mf_lib/mf_list.h"
//#include "tests_lib/tests.h"

//test_ex05 | ft_list_push_strs ft_list_clear
void	test_ex05();
//test ex07 | ft_list_at.c
void	test_ex07(t_list *begin_list);
//test ex08 | ft_list_reverse
void	test_ex08(t_list **begin_list);

//test ex14
void	test_ex14(t_list **begin_list);


void test();
void test2();
int int_cmp(void *data1, void *data2);

void test_ex15();

int cmp(void *data, void *ref);

void test_for();

int main(void)
{
	test_for();
	//test_ex15();
}



void test_ex05(void)
{
	t_list	*begin_list;
	char	**strs;

	printf("\n||||| TEST EX05 |||||\n\n");
	strs = mf_creat_str_list();
	begin_list = ft_list_push_strs(3, strs);
	mf_print_list_strs(begin_list);
	ft_list_clear(begin_list, free);
	free(strs);
	printf("\n||| END TEST EX05 |||\n");
}

void	test_ex07(t_list *begin_list)
{
	t_list	*p;

	printf("\n||||| TEST EX07 |||||\n");
	if(p = ft_list_at(begin_list, 0))
		printf("Data of element zero is %i.\n", *(int*)p -> data);
	else
		printf("There is no elemen zero.\n");
	if(p = ft_list_at(begin_list, 10))
		printf("Data of element eleven is %i.\n", *(int*)p -> data);
	else
		printf("There is no element eleven.\n");
	printf("\n||| END TEST EX07 |||\n");
}

void	test_ex08(t_list **begin_list){
	printf("\n||||| TEST EX08 |||||\n");
	printf("Before reverse:\n");
	mf_print_list(*begin_list);
	ft_list_reverse(begin_list);
	printf("After reverse:\n");
	mf_print_list(*begin_list);
	printf("\n||| END TEST EX08 |||\n");
}


void test()
{
	t_list **begin;
	t_list *begin_list;
	int number;

	begin = &begin_list;
	begin_list = NULL;
	number = 42;

	ft_list_push_back(begin, &number);
	printf("Data of the last element: %i\n", * (int * )ft_list_last(begin_list) -> data);
}

void test2()
{
	t_list **begin;
	t_list *begin_list;
	int *number;

	begin = &begin_list;
	begin_list = NULL;
	number = malloc(sizeof(int));
	*number = 42;

	ft_list_push_back(begin, number);
	printf("Data of the last element: %i\n", * (int * )ft_list_last(begin_list) -> data);
	free(number);
}

void	test_ex14(t_list **begin_list)
{
	ft_list_sort(begin_list, int_cmp);
	mf_print_list(*begin_list);
}

int int_cmp(void *data1, void *data2)
{
	if (*(int*)data1 > *(int*)data2)
		return (1);
	if (*(int*)data1 < *(int*)data2)
		return (-1);
	return (0);
}

void test_ex15()
{
	t_list	*begin_list;
	int		*number;

	printf("Insert number 50 into the empty list\n");
	begin_list = mf_make_list_random_numbers(0);
	number = malloc(sizeof(int));
	*number = 50;
	ft_sorted_list_insert(&begin_list, number, int_cmp);
	mf_print_list(begin_list);
	printf("Insert number 52 into the list\n");
	number = malloc(sizeof(int));
	*number = 52;
	ft_sorted_list_insert(&begin_list, number, int_cmp);
	mf_print_list(begin_list);
	printf("Insert number 42 into the list\n");
	number = malloc(sizeof(int));
	*number = 42;
	ft_sorted_list_insert(&begin_list, number, int_cmp);
	mf_print_list(begin_list);
	printf("Insert number 42 into the list\n");
	number = malloc(sizeof(int));
	*number = 42;
	ft_sorted_list_insert(&begin_list, number, int_cmp);
	mf_print_list(begin_list);
	printf("Insert number 51 into the list\n");
	number = malloc(sizeof(int));
	*number = 51;
	ft_sorted_list_insert(&begin_list, number, int_cmp);
	mf_print_list(begin_list);
	ft_list_clear(begin_list, free);
}


void test_for()
{
	t_list	*begin_list;
	int		*ref;

	ref = malloc(sizeof(int));
	*ref = 49;

	begin_list = mf_make_list_random_numbers(10);
	mf_print_list(begin_list);
	ft_list_remove_if(&begin_list, ref, cmp, free);

	mf_print_list(begin_list);

	free(ref);
	ft_list_clear(begin_list, free);


	
}

int cmp(void *data, void *ref)
{
	//printf("%i > %i = %i\n",*(int*)data, *(int*)ref, *(int*)data > *(int*)ref);
	return (!(*(int*)data > *(int*)ref));
}