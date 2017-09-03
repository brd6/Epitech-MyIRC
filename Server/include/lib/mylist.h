/*
** mylist.h for mylist in /home/bongol_b/rendu/Piscine_C_J11
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 09:29:09 2015 berdrigue bongolo-beto
** Last update Sat Jun  3 11:28:41 2017 bongol_b
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct s_list	t_list;

struct		s_list
{
  void		*data;
  t_list	*next;
};

/*
** Simple linked list
*/
void		*my_find_elm_eq_in_list(t_list *begin, void *dat, int (*cmp)());
t_list		*my_find_node_eq_in_list(t_list *begin, void *da, int (*cmp)());
int		my_add_elem_in_list_end(t_list **begin, void *data);
int		my_add_elem_in_list_begin(t_list **begin, void *data);
void		my_rm_elem_in_list_end(t_list **begin);
int		my_apply_on_list(t_list *begin, void (*f)(void*));
int		my_rm_el_from_list(t_list **begin, void *dat, int (*cmp)());
int		my_rm_all_eq_from_list(t_list **begin, void *dat, int (*cmp)());
char		**my_list_to_wordtab(t_list *begin);
int		my_list_size(t_list *begin);
void		my_free_list(t_list **begin);
void		my_apply_elm_eq_in_list(t_list *, int (*)(), void *, int (*)());

#endif /* !MYLIST_H_ */
