#ifndef FT_LIST_H
#define FT_LIST_H

#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

//ex00
t_list	*ft_create_elem(void *data);
//ex01
void	ft_list_push_front(t_list **begin_list, void *data);
//ex02
int		ft_list_size(t_list *begin_list);
//ex03
t_list	*ft_list_last(t_list *begin_list);
//ex04
void	ft_list_push_back(t_list **begin_list, void *data);
//ex05
t_list	*ft_list_push_strs(int size, char **strs);
//ex06
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
//ex07
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
//ex08
void	ft_list_reverse(t_list **begin_list);
//ex09
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
//ex10
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
//ex11
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
//ex12
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
//ex13
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
//ex14
void	ft_list_sort(t_list **begin_list, int (*cmp)());
//ex15
void ft_list_reverse_fun(t_list *begin_list);
//ex16
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
//ex17
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());


#endif
