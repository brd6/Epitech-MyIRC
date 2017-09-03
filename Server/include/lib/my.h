/*
** my.h for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/include
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May 31 16:38:37 2017 bongol_b
** Last update Thu Jun  8 19:35:14 2017 bongol_b
*/

#ifndef MY_H_
# define MY_H_

# include "mylist.h"

char		**my_str_split(const char *str, const char *sp);
int		my_get_char_pos(const char *str, char c);
void		my_free_wordtab(char **tab);
int		my_add_elem_in_list_begin(t_list **begin, void *data);
void		*my_find_elm_eq_in_list(t_list *begin,
					void *data_tef,
					int (*cmp)());
char		**my_str_split(const char *str, const char *sp);
int		my_wordtab_count(const char **tab);

#endif /* !MY_H_ */
