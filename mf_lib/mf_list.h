#ifndef MF_LIST_H
#define MF_LIST_H

#include "../ft_lib/ft_list.h"

#include <stdio.h>
#include <time.h>

void	mf_print_list(t_list *begin_list);
void	mf_print_list_strs(t_list *begin_list);
t_list  *mf_make_list_random_numbers(int n);
char	**mf_creat_str_list();

#endif